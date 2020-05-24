#ifndef TWOLIST_H_INCLUDED
#define TWOLIST_H_INCLUDED

using namespace std;
template <class T>
struct Node {

  Node() : prev(this), next(this) {}

  Node(Node *next_, const T &data_)
    : prev(next_->prev), next(next_), data(data_) {
    prev->next = next->prev = this;
  }

   ~Node() {
    prev->next = next;
    next->prev = prev;
  }
  Node *prev, *next;
  T data;
};

// шаблонный класс
template <class T>
class twoList {
 public:
  // конструктор
  twoList() : base(new Node<T>()) {}
  // конструктор копирования
  twoList(const twoList<T> &other) : base(new Node<T>()) {
    copyFrom(other);
  }
  // деструктор
  ~twoList() { clear(); delete base; }
  // оператор присваивания
  twoList<T> operator=(const twoList<T> &other) {
    if (&other != this) {
      clear();
      copyFrom(other);
    }
    return *this;
  }
  // проверка на пустоту
  bool empty() { return base->next == base; }
  // очистка связного списка
  void clear() {
    while (!empty())  delete base->next;
  }
  // вычисление размера
  size_t size() const {
    size_t size = 0;
    for (Node<T> *node = base->next; node != base; node = node->next)
      ++size;
    return size;
  }
  // копирование
  void copyFrom(const twoList<T> &other) {
    for (size_t i = 0; i < other.size(); ++i)
      pushBack(other.get(i));
  }
  // добавление в конец
  void pushBack(const T &value) {
    new Node<T>(base, value);
  }
  // добавление в начало списка
  void pushFront(const T &value) {
    new Node<T>(base->next, value);
  }
  // первый элемент списка
  const T &front() const {
    return base->next->data;
  }
  // последний элемент списка
  const T &back() const {
    return base->prev->data;
  }
  // удаление первого элемента связного списка
  T popFront() {
    T result = front();
    delete base->next;
    return result;
  }
  // удаление последнего элемента связного списка
  T popBack() {
    T result = back();
    delete base->prev;
    return result;
  }
  // вставка данных перед индексом
  void insert(size_t beforeIndex, const T &value) {
    Node<T> *before = base->next;
    while (beforeIndex-- > 0) before = before->next;
    new Node<T>(before, value);
  }

  // получение данных по индексу
  const T &get(size_t n) const {
    Node<T> *result = base->next;
    while (n-- > 0) result = result->next;
    return result->data;
  }

  //получение элемента оператором
  const T &operator[](size_t n) const { return get(n); }

 private:
  // нулевой элемент связного списка
  Node<T> *base;
};


#endif // TWOLIST_H_INCLUDED
