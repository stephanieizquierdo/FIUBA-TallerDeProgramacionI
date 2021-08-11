/*
Escriba un programa que imprima por salida estándar los números entre 1 y 100, en orden
ascendente. Se pide que los números sean contabilizados por una variable global única y que
los pares sean escritos por un hilo mientras que los impares sean escritos por otro.
Contemple la correcta sincronización entre hilos y la liberación de los recursos utilizados.
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

int contador = 1;
std::mutex m;
std::condition_variable condicion;

void imprimir(bool es_impar, int max){
    while(contador < max){
        std::unique_lock<std::mutex> lk(m);
        condicion.wait(lk, [&](){return contador%2 == es_impar;});
        std::cout << contador++ << ' ' << std::endl;
        lk.unlock();
        condicion.notify_all();
    }
}

int main(){
    std::thread hiloImpar(imprimir, true, 100);
    std::thread hiloPar(imprimir, false, 100);
    hiloImpar.join();
    hiloPar.join();
    return 0;
}
