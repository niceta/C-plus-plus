#include <map>
#include <string>
#include <tuple>
using namespace std;

// ������������ ��� ��� ������� ������
//enum class TaskStatus {
//	NEW,          // �����
//	IN_PROGRESS,  // � ����������
//	TESTING,      // �� ������������
//	DONE          // ���������
//};

// ��������� ���-������� ��� map<TaskStatus, int>,
// ������������ ������� ���������� ����� ������� �������
//using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
	// �������� ���������� �� �������� ����� ����������� ������������
	const TasksInfo& GetPersonTasksInfo(const string& person) const {
		return persons.at(person);
	}

	// �������� ����� ������ (� ������� NEW) ��� ����������� �������������
	void AddNewTask(const string& person) {
		++persons[person][TaskStatus::NEW];
	}

	void AddInProgTask(const string& person) {
		++persons[person][TaskStatus::IN_PROGRESS];
	}

	void AddTestTask(const string& person) {
		++persons[person][TaskStatus::NEW];
	}

	// �������� ������� �� ������� ���������� ����� ����������� ������������,
	// ����������� ��. ����
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(
		const string& person, int task_count) {

		tuple<TasksInfo, TasksInfo> result;
		int counter = 0;
		int undone_tasks = persons[person][TaskStatus::NEW] +
			persons[person][TaskStatus::IN_PROGRESS] +
			persons[person][TaskStatus::TESTING];

		if (task_count > undone_tasks) {
			task_count = undone_tasks;
		}

		TasksInfo updated,
			not_updated = persons[person];

		for (const auto &item : persons[person]) {
			if (item.first== TaskStatus::DONE) {
				break;
			}
			if (item.second == 0) {
				not_updated.erase(item.first);
				continue;
			}
			if (task_count >= item.second) {
				if (item.first == TaskStatus::NEW) {
					updated[TaskStatus::IN_PROGRESS] = item.second;
				}
				if (item.first == TaskStatus::IN_PROGRESS) {
					updated[TaskStatus::TESTING] = item.second;
				}
				if (item.first == TaskStatus::TESTING) {
					updated[TaskStatus::DONE] = item.second;
				}
				not_updated.erase(item.first);
				task_count -= item.second;
				persons[person][item.first] = 0;
			}
			else {
				if (item.first == TaskStatus::NEW) {
					updated[TaskStatus::IN_PROGRESS] = task_count;
				}
				if (item.first == TaskStatus::IN_PROGRESS) {
					updated[TaskStatus::TESTING] = task_count;
				}
				if (item.first == TaskStatus::TESTING) {
					updated[TaskStatus::DONE] = task_count;
				}
				not_updated[item.first] -= task_count;
				persons[person][item.first] -= task_count;
			}

		}

		for (const auto &item : updated) {
			persons[person][item.first] += item.second;
		}

		result = make_tuple(updated, not_updated);
		return result;
	}

private:
	map<string, TasksInfo> persons;
};