#include <iostream>
#include <map>
#include <string>
#include <tuple>

#include "TeamTasks2.h"

using namespace std;

void PrintTasksInfo(TasksInfo tasks_info) {
	cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
		", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
		", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
		", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) =
    tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) =
    tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
	return 0;
}

/*TeamTasks tasks;
for (int i = 0; i < 2; ++i) {
tasks.AddInProgTask("Alice");
}
for (int i = 0; i < 3; ++i) {
tasks.AddNewTask("Alice");
}
for (int i = 0; i < 4; ++i) {
tasks.AddTestTask("Alice");
}
tasks.persons["Alice"][TaskStatus::DONE]++;
TasksInfo updated_tasks, untouched_tasks;
tie(updated_tasks, untouched_tasks) =
tasks.PerformPersonTasks("Alice", 4);

tie(updated_tasks, untouched_tasks) =
tasks.PerformPersonTasks("Alice", 5);
cout << "Updated Alice's tasks: ";
PrintTasksInfo(updated_tasks);
cout << "Untouched Alice's tasks: ";
PrintTasksInfo(untouched_tasks);

tie(updated_tasks, untouched_tasks) =
tasks.PerformPersonTasks("Alice", 5);
cout << "Updated Alice's tasks: ";
PrintTasksInfo(updated_tasks);
cout << "Untouched Alice's tasks: ";
PrintTasksInfo(untouched_tasks);

tie(updated_tasks, untouched_tasks) =
tasks.PerformPersonTasks("Alice", 1);
cout << "Updated Alice's tasks: ";
PrintTasksInfo(updated_tasks);
cout << "Untouched Alice's tasks: ";
PrintTasksInfo(untouched_tasks);

for (int i = 0; i < 5; ++i) {
tasks.AddNewTask("Alice");
}
tie(updated_tasks, untouched_tasks) =
tasks.PerformPersonTasks("Alice", 2);
cout << "Updated Alice's tasks: ";
PrintTasksInfo(updated_tasks);
cout << "Untouched Alice's tasks: ";
PrintTasksInfo(untouched_tasks);

PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

tie(updated_tasks, untouched_tasks) =
tasks.PerformPersonTasks("Alice", 4);
cout << "Updated Alice's tasks: ";
PrintTasksInfo(updated_tasks);
cout << "Untouched Alice's tasks: ";
PrintTasksInfo(untouched_tasks);

PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));*/