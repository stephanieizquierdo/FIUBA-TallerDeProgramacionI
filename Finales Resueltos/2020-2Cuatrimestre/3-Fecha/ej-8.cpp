/*Implemente una función C++ denominada SoloMuliplos que reciba una
lista de elementos numéricos y un elemnto numérico x. La función debe
devolver una nueva lista con los elementos de la primera que sean múltiplos de x:
		std::list<T> SoloMultiplos(std::list<T> a,T x);
*/

std::list<T> SoloMultiplos(std::list<T> a,T x){
    std::list<T> resultado;
    for(auto it = a.begin(), it!= a.end() , it++){
        auto item = *it;
        if(item%x ==0){//es multiplo
            resultado.push_back(item);
        }
    }
    return resultado;
}
