#pragma once
#include <map>
#include <string>
#include <tuple>
using namespace std;

// ������������ ��� ��� ������� ������
enum class TaskStatus {
	NEW,          // �����
	IN_PROGRESS,  // � ����������
	TESTING,      // �� ������������
	DONE          // ���������
};

// ��������� ���-������� ��� map<TaskStatus, int>,
// ������������ ������� ���������� ����� ������� �������
using TasksInfo = map<TaskStatus, int>;

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

		for (const auto &[key, value] : persons[person]) {
			if (key == TaskStatus::DONE) {
				break;
			}
			if (value == 0) {
				not_updated.erase(key);
				continue;
			}
			if (task_count >= value) {
				if (key == TaskStatus::NEW) {
					updated[TaskStatus::IN_PROGRESS] = value;
				}
				if (key == TaskStatus::IN_PROGRESS) {
					updated[TaskStatus::TESTING] = value;
				}
				if (key == TaskStatus::TESTING) {
					updated[TaskStatus::DONE] = value;
				}
				not_updated.erase(key);
				task_count -= value;
				persons[person][key] = 0;
			}
			else {
				if (key == TaskStatus::NEW) {
					updated[TaskStatus::IN_PROGRESS] = task_count;
				}
				if (key == TaskStatus::IN_PROGRESS) {
					updated[TaskStatus::TESTING] = task_count;
				}
				if (key == TaskStatus::TESTING) {
					updated[TaskStatus::DONE] = task_count;
				}
				not_updated[key] -= task_count;
				persons[person][key] -= task_count;
			}

		}

		for (const auto &[key, value] : updated) {
			persons[person][key] += value;
		}

		result = make_tuple(updated, not_updated);
		return result;
	}

private:
	map<string, TasksInfo> persons;
};