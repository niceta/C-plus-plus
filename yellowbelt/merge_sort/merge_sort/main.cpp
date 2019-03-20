#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

/*template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  // 1st
  if (range_end - range_begin < 2) {
    return;
  }
  // 2nd
  //vector<typename RandomIt::value_type> elements(range_begin, range_end);
  // 3rd
  auto middle = next(range_begin, distance(range_begin, range_end) / 2);
  vector<typename RandomIt::value_type> first(range_begin, middle);
  vector<typename RandomIt::value_type> second(middle, range_end);
  // 4th
  MergeSort(first.begin(), first.end());
  MergeSort(second.begin(), second.end());
  // 5th
  merge(first.begin(), first.end(),
    second.begin(), second.end(),
    range_begin);
}
*/
//template <typename RandomIt>
//void MergeSort(RandomIt range_begin, RandomIt range_end) {
//  // 1st
//  if (range_end - range_begin < 2) {
//    return;
//  }
//  // 2nd
//  //vector<typename RandomIt::value_type> elements(range_begin, range_end);
//  // 3rd
//  auto middle1 = next(range_begin, distance(range_begin, range_end) / 3);
//  vector<typename RandomIt::value_type> first(range_begin, middle1);
//  auto middle2 = next(range_begin, distance(range_begin, range_end) * 2 / 3);
//  vector<typename RandomIt::value_type> second(middle1, middle2);
//  vector<typename RandomIt::value_type> third(middle2, range_end);
//  // 4th
//  MergeSort(first.begin(), first.end());
//  MergeSort(second.begin(), second.end());
//  MergeSort(third.begin(), third.end());
//  // 5th
//  vector<typename RandomIt::value_type> temp;
//  merge(first.begin(), first.end(),
//    second.begin(), second.end(),
//    back_inserter(temp));
//  merge(temp.begin(), temp.end(),
//    third.begin(), third.end(),
//    range_begin);
//}

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  // 1. Если диапазон содержит меньше 2 элементов, выходим из функции
  int range_length = range_end - range_begin;
  if (range_length < 2) {
    return;
  }

  // 2. Создаем вектор, содержащий все элементы текущего диапазона
  vector<typename RandomIt::value_type> elements(range_begin, range_end);

  // 3. Разбиваем вектор на две равные части
  auto mid = elements.begin() + range_length / 2;

  // 4. Вызываем функцию MergeSort от каждой половины вектора
  MergeSort(elements.begin(), mid);
  MergeSort(mid, elements.end());

  // 5. С помощью алгоритма merge сливаем отсортированные половины
  // в исходный диапазон
  // merge -> http://ru.cppreference.com/w/cpp/algorithm/merge
  merge(elements.begin(), mid, mid, elements.end(), range_begin);
}

template <typename RandomIt>
void MergeSort2(RandomIt range_begin, RandomIt range_end) {
  // 1. Если диапазон содержит меньше 2 элементов, выходим из функции
  int range_length = range_end - range_begin;
  if (range_length < 2) {
    return;
  }

  // 2. Создаем вектор, содержащий все элементы текущего диапазона
  vector<typename RandomIt::value_type> elements(range_begin, range_end);

  // 3. Разбиваем вектор на три равные части
  auto one_third = elements.begin() + range_length / 3;
  auto two_third = elements.begin() + range_length * 2 / 3;

  // 4. Вызываем функцию MergeSort от каждой трети вектора
  MergeSort2(elements.begin(), one_third);
  MergeSort2(one_third, two_third);
  MergeSort2(two_third, elements.end());

  // 5. С помощью алгоритма merge cливаем первые две трети во временный вектор
  // back_inserter -> http://ru.cppreference.com/w/cpp/iterator/back_inserter
  vector<typename RandomIt::value_type> interim_result;
  merge(elements.begin(), one_third, one_third, two_third,
    back_inserter(interim_result));

  // 6. С помощью алгоритма merge сливаем отсортированные части
  // в исходный диапазон
  // merge -> http://ru.cppreference.com/w/cpp/algorithm/merge
  merge(interim_result.begin(), interim_result.end(), two_third, elements.end(),
    range_begin);
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindSegment(
  RandomIt range_begin, RandomIt range_end, int left, int right) {
  // ТЕЛО ФУНКЦИИ
  return { lower_bound(range_begin, range_end, left),
    upper_bound(range_begin, range_end, right) };
}

int main() {
  
  vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };

  MergeSort(begin(v), end(v));
  auto p = FindSegment(v.begin(), v.end(), 4, 5);
  for (auto it = p.first; it != p.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}