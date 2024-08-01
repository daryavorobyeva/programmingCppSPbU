#include <iostream>
#include "stack.h"
#include "queue.h"
#include "list.h"

using namespace std;

int main() {
    Stack s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << s1 << endl;         // 3->2->1
    cout << s1.size() << endl;

    Stack s2(s1), s3;

    s1.pop();
    s1.push(4);
    s1.push(5);

    s2.pop();
    s2.push(6);

    cout << s1 << endl;         // 5->4->2->1
    cout << s1.size() << endl;

    cout << s2 << endl;         // 6->2->1
    cout << s2.size() << endl;

    s3 = s1;

    s1.pop();
    s1.push(7);
    s1.push(8);

    s3.pop();
    s3.push(9);

    cout << s1 << endl;         // 8->7->4->2->1
    cout << s1.size() << endl;

    cout << s2 << endl;         // 6->2->1
    cout << s2.size() << endl;

    cout << s3 << endl;         // 9->4->2->1
    cout << s3.size() << endl;

    Queue q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);

    cout << q1 << endl;          // 1->2->3
    cout << q1.size() << endl;

    Queue q2(q1), q3;

    q1.pop();
    q1.push(4);
    q1.push(5);

    q2.pop();
    q2.push(6);

    cout << q1 << endl;         // 2->3->4->5
    cout << q1.size() << endl;

    cout << q2 << endl;         // 2->3->6
    cout << q2.size() << endl;

    q3 = q1;

    q1.pop();
    q1.push(7);
    q1.push(8);

    q3.pop();
    q3.push(9);

    cout << q1 << endl;         // 3->4->5->7->8
    cout << q1.size() << endl;

    cout << q2 << endl;         // 2->3->6
    cout << q2.size() << endl;

    cout << q3 << endl;
    cout << q3.size() << endl;  // 3->4->5->9

    return 0;
}
