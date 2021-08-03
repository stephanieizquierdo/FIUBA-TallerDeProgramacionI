/*
Implemente una función C++ denominada DobleSegunda que reciba dos listas de elementos
y devuelva una nueva lista duplicando los elementos de la primera si están en la segunda:
std::list<T> DobleSegunda(std::list<T> a,std::list<T> b);
*/


std::list<T> DobleSegunda(std::list<T> a,std::list<T> b) {
    std::list<T> resultado;
    for(auto it = a.begin(); it != a.end(); it++){
        auto item = std::find(b.begin(), b.end(), *it);
        if(elemento != b.end()){
            pushback(resultado, elemento);
        }
        pushback(resultado, elemento);
    }
    return resultado;
}
