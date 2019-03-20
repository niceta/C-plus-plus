#include <map>
#include <string>
#include <tuple>
using namespace std;

#include <algorithm>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

// Выделим в отдельную функцию получение следующего по приоритету типа задачи
// Функция налагает требование на входной параметр: он не должен быть равен DONE
// При этом task_status явно не сравнивается с DONE, что позволяет
// сделать эту функцию максимально эффективной
TaskStatus Next(TaskStatus task_status) {
  return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const;

  // Добавить новую задачу (в статусе NEW) для конкретного разработчика
  void AddNewTask(const string& person);

  // Обновить статусы по данному количеству задач конкретного разработчика
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
    const string& person, int task_count);

private:
  map<string, TasksInfo> person_tasks_;
};

const TasksInfo& TeamTasks::GetPersonTasksInfo(const string& person) const {
  return person_tasks_.at(person);
}

void TeamTasks::AddNewTask(const string& person) {
  ++person_tasks_[person][TaskStatus::NEW];
}

// Функция для удаления нулей из словаря
void RemoveZeros(TasksInfo& tasks_info) {
  // Соберём те статусы, которые нужно убрать из словаря
  vector<TaskStatus> statuses_to_remove;
  for (const auto& task_item : tasks_info) {
    if (task_item.second == 0) {
      statuses_to_remove.push_back(task_item.first);
    }
  }
  for (const TaskStatus status : statuses_to_remove) {
    tasks_info.erase(status);
  }
}


tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(
  const string& person, int task_count) {
  TasksInfo updated_tasks, untouched_tasks;

  // Здесь и далее мы будем пользоваться тем фактом, что в std::map оператор [] 
  // в случае отсутствия ключа инициализирует значение по умолчанию,
  // если это возможно.
  // std::map::operator[] ->
  // http://ru.cppreference.com/w/cpp/container/map/operator_at
  TasksInfo& tasks = person_tasks_[person];

  // Посчитаем, сколько задач каждого из статусов нужно обновить, 
  // пользуясь тем фактом, что по умолчанию enum class инциализирует значения
  // от нуля по возрастанию.
  // enum class -> http://ru.cppreference.com/w/cpp/language/enum
  for (TaskStatus status = TaskStatus::NEW;
    status != TaskStatus::DONE;
    status = Next(status)) {
    // Считаем обновлённые
    updated_tasks[Next(status)] = min(task_count, tasks[status]);
    // Считаем, сколько осталось обновить
    task_count -= updated_tasks[Next(status)];
  }

  // Обновляем статус текущих задач в соответствии с информацией об обновлённых 
  // и находим количество нетронутых
  for (TaskStatus status = TaskStatus::NEW;
    status != TaskStatus::DONE;
    status = Next(status)) {
    untouched_tasks[status] = tasks[status] - updated_tasks[Next(status)];
    tasks[status] += updated_tasks[status] - updated_tasks[Next(status)];
  }
  // По условию, DONE задачи не нужно возвращать в не обновлённых задачах
  tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];

  // По условию в словарях не должно быть нулей
  RemoveZeros(updated_tasks);
  RemoveZeros(untouched_tasks);

  return { updated_tasks, untouched_tasks };
}

/*
class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const {
  	return persons.at(person);
  }

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person) {
  	++persons[person][TaskStatus::NEW];
  }

  void AddInProgTask(const string& person) {
	++persons[person][TaskStatus::IN_PROGRESS];
  }

  void AddTestTask(const string& person) {
    ++persons[person][TaskStatus::TESTING];
  }

  void updateTasks(TasksInfo& current, TasksInfo& update,
      TaskStatus new_status, TaskStatus old_status, int& task_count) {
    if (task_count == 0) return;
    if (task_count - current[old_status] > 0) {
      update[new_status] = current[old_status];
      task_count -= current[old_status];
      current.erase(old_status);
    }
    else {
      update[new_status] = task_count;
      current[old_status] -= task_count;
      task_count = 0;
    }
  }
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count) {
    
    tuple<TasksInfo, TasksInfo> result;
    TasksInfo tasksInfo = persons[person];
    TasksInfo updatedInfo;

    updateTasks(tasksInfo, updatedInfo, TaskStatus::IN_PROGRESS, TaskStatus::NEW, task_count);
    updateTasks(tasksInfo, updatedInfo, TaskStatus::TESTING, TaskStatus::IN_PROGRESS, task_count);
    updateTasks(tasksInfo, updatedInfo, TaskStatus::DONE, TaskStatus::TESTING, task_count);
    
    persons[person][TaskStatus::NEW] = tasksInfo[TaskStatus::NEW] + updatedInfo[TaskStatus::NEW];
    persons[person][TaskStatus::IN_PROGRESS] = tasksInfo[TaskStatus::IN_PROGRESS] + updatedInfo[TaskStatus::IN_PROGRESS];
    persons[person][TaskStatus::TESTING] = tasksInfo[TaskStatus::TESTING] + updatedInfo[TaskStatus::TESTING];
    persons[person][TaskStatus::DONE] = tasksInfo[TaskStatus::DONE] + updatedInfo[TaskStatus::DONE];

    if (tasksInfo.count(TaskStatus::DONE) > 0) tasksInfo.erase(TaskStatus::DONE);
    return {updatedInfo, tasksInfo};
  }

private:
  map<string, TasksInfo> persons;
};
/*