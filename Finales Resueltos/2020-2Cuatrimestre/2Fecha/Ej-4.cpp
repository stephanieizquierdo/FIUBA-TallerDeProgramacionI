/*
Implemente una función C++ denominada DUPLICAR que reciba dos listas de elementos
y devuelva una nueva lista duplicando los elementos de la primera
 que están en la segunda:
*/

std::list<T> Duplicar(std::list<T> a,std::list<T> b){
    std::list<T> resultado;
    for(auto it = a.begin(); it != a.end(); it++){
        auto elemento = std::find(b.begin(), b.end(), *it);
        if(elemento != b.end()){
            resultado.pushback(elemento);
        }
        resultado.pushback(*it);
    }
    return resultado;
}
