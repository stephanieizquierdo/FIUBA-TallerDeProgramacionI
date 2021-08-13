/*

 Implemente una función C++ denominada Sacar que reciba dos listas de elementos
 y devuelva una nueva lista con los elementos de la primera que no están en la segunda:

*/

std::list<T> sacar(std::list<T> a, std::list<T> b){
    std::list resultado;
    for(auto it = a.begin(), it != a.endl(), it++){
        auto item = std::find(b.begin(), b.end(), *it);
        if(item == b.end()){ //significa que no esta
            resultado.pushback(*it);
        }
    }
    return resultado;
}
