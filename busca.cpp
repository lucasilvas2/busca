#include <iostream>
#include <random>
#include <chrono>

using namespace std;

//Função para gerar valores aleatorios
//Utiliza o min e max para gerar os numeros de forma crescente
int gerando(int min, int max){
    random_device rd; 
    default_random_engine gen;
    uniform_int_distribution<> dis(min, max);
    return round(dis(gen));
}

int busca_binaria(int k, int * colecao, int tamanho){
    int inicio = 0, fim = tamanho - 1, meio;
    while (inicio <= fim)               
    {
        meio = (inicio + fim) / 2;
        if(k < colecao[meio]){
            fim = meio - 1;
        }
        else if(k > colecao[meio]){
            inicio = meio + 1;
        }
        else{
            return meio;
        }
    }
    return -1;
}

int busca_linear(int k, int colecao[], int tamanho){
    int posicao = 0;
    do
    {
        //cout << "Pos = " << colecao[posicao] << endl;
        if(k == colecao[posicao]){
            return posicao;
        }
        posicao++;
    } while (posicao < tamanho);
    return -1; 
}

int main(int argc, char const *argv[])
{
    //O min/max utiliza para definir um range para a geracao dos valores e garantir que seja de forma crescente
    int min = 1 , max = 5;
    //Alterar para o valor do tamanho do vetor que deseja criar
    int tam_lista = 3000;

    int lista[tam_lista];
    lista[0] = 0; //Garantido que a lista inicie com 0
    for(int i = 1; i < tam_lista; i++){
        lista[i] = gerando(min, max);
        min += 5;
        max += 5;
        
    }
    //Saber qual o valor do último N gerado
    cout << "Último elemento da lista: "<<lista[tam_lista - 1] <<endl;
    cout << "Verificando o tamanho do vetor: " << sizeof(lista) / 4 << endl << endl;
    int x;
    double time_total_linear = 0, time_total_binaria = 0;
    
    min = 0;
    max = 1;
    int pos = 0;
    for(int i = 0; i < 20; i++){
        
        x = gerando(min, max);
        //Valores do min/max pode ser alterado manualmente para que na busca alcance o último elemento do vetor
        min += 5;
        max += 10;
        //cout << "Buscando o número: " << x << endl;
        auto inicio_linear = chrono::steady_clock::now();
        pos = busca_linear(x, lista, tam_lista);
        auto final_linear = chrono::steady_clock::now();;

        //cout << pos << endl;
        auto time = chrono::duration_cast<chrono::nanoseconds>(final_linear - inicio_linear).count();
        time_total_linear += time;
        //cout << "Time = " << time << endl;
    }
    
    cout << "Time Total Linear = " << time_total_linear << endl;
    cout << "Media Linear= " << (time_total_linear / 20) << endl << endl << endl;
    
    min = 0;
    max = 1;
    for(int i = 0; i < 20; i++){
        
        x = gerando(min, max);
        //Valores do min/max pode ser alterado manualmente para que na busca alcance o último elemento do vetor
        min += 5;
        max += 1;
        //cout << "Buscando o número: " << x << endl;
        auto inicio_binaria = chrono::steady_clock::now();
        pos = busca_binaria(x, lista, tam_lista);
        auto final_binaria = chrono::steady_clock::now();;

        //cout << pos << endl;
        auto time = chrono::duration_cast<chrono::nanoseconds>(final_binaria - inicio_binaria).count();
        time_total_binaria += time;
        //cout << "Time = " << time << endl;
    }
    
    cout << "Time Total Binaria= " << time_total_binaria << endl;
    cout << "Media Binaria = " << (time_total_binaria / 20) << endl;
    
    
    return 0;
}