template <typename T1>
Demo<T1>::Demo() {
    a = 1;
    b = 1;
}
 
template <typename T1>
Demo<T1>::Demo(T1 n) {
    a = n;
    b = n;
}
 
template <typename T1>
Demo<T1>::Demo(T1 n1, T1 n2) {
    a = n1;
    b = n2;
}
 
template <typename T1>
T1 Demo<T1>::do_something() {
    return getA() + getB();
}
 
template <typename T1>
void Demo<T1>::setA(T1 n) {
    a = n;
}
 
template <typename T1>
void Demo<T1>::setB(T1 n) {
    b = n;
}
 
template <typename T1>
T1 Demo<T1>::getA() {
    return a;
}
 
template <typename T1>
T1 Demo<T1>::getB() {
    return b;
}