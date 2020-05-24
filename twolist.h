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

// ��������� �����
template <class T>
class twoList {
 public:
  // �����������
  twoList() : base(new Node<T>()) {}
  // ����������� �����������
  twoList(const twoList<T> &other) : base(new Node<T>()) {
    copyFrom(other);
  }
  // ����������
  ~twoList() { clear(); delete base; }
  // �������� ������������
  twoList<T> operator=(const twoList<T> &other) {
    if (&other != this) {
      clear();
      copyFrom(other);
    }
    return *this;
  }
  // �������� �� �������
  bool empty() { return base->next == base; }
  // ������� �������� ������
  void clear() {
    while (!empty())  delete base->next;
  }
  // ���������� �������
  size_t size() const {
    size_t size = 0;
    for (Node<T> *node = base->next; node != base; node = node->next)
      ++size;
    return size;
  }
  // �����������
  void copyFrom(const twoList<T> &other) {
    for (size_t i = 0; i < other.size(); ++i)
      pushBack(other.get(i));
  }
  // ���������� � �����
  void pushBack(const T &value) {
    new Node<T>(base, value);
  }
  // ���������� � ������ ������
  void pushFront(const T &value) {
    new Node<T>(base->next, value);
  }
  // ������ ������� ������
  const T &front() const {
    return base->next->data;
  }
  // ��������� ������� ������
  const T &back() const {
    return base->prev->data;
  }
  // �������� ������� �������� �������� ������
  T popFront() {
    T result = front();
    delete base->next;
    return result;
  }
  // �������� ���������� �������� �������� ������
  T popBack() {
    T result = back();
    delete base->prev;
    return result;
  }
  // ������� ������ ����� ��������
  void insert(size_t beforeIndex, const T &value) {
    Node<T> *before = base->next;
    while (beforeIndex-- > 0) before = before->next;
    new Node<T>(before, value);
  }

  // ��������� ������ �� �������
  const T &get(size_t n) const {
    Node<T> *result = base->next;
    while (n-- > 0) result = result->next;
    return result->data;
  }

  //��������� �������� ����������
  const T &operator[](size_t n) const { return get(n); }

 private:
  // ������� ������� �������� ������
  Node<T> *base;
};


#endif // TWOLIST_H_INCLUDED
