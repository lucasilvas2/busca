#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int alcance_min(int tam_vetor);
int alcance_max(int tam_vetor);
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
        if(k == colecao[posicao]){
            return posicao;
        }
        posicao++;
    } while (posicao < tamanho);
    return -1; 
}

int main(int argc, char const *argv[])
{
    int entrada = atoi(argv[1]);
    //O min/max utiliza para definir um range para a geracao dos valores e garantir que seja de forma crescente
    int min = 1 , max = 5;
    //Alterar para o valor do tamanho do vetor que deseja criar
    int tam_lista = entrada;

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
    for(int i = 0; i < 30; i++){
        
        x = gerando(min, max);
        //Valores do min/max pode ser alterado manualmente para que na busca alcance o último elemento do vetor
        //min += 58;
        //max += 95;
        min += alcance_min(tam_lista);
        max += alcance_max(tam_lista);
        //cout << "Buscando o número: " << x << endl;
        auto inicio_linear = chrono::steady_clock::now();
        pos = busca_linear(x, lista, tam_lista);
        auto final_linear = chrono::steady_clock::now();;

        //cout << pos << endl;
        auto time = chrono::duration_cast<chrono::nanoseconds>(final_linear - inicio_linear).count();
        time_total_linear += time;
        //cout << "Time = " << time << endl;
    }
    //cout << "Buscando o número: " << x << endl;
    cout << "Time Total Linear = " << time_total_linear << endl;
    cout << "Media Linear= " << (time_total_linear / 30) << endl << endl;
    pos = 0;
    min = 0;
    max = 1;
    for(int i = 0; i < 30; i++){
        
        x = gerando(min, max);
        //Valores do min/max pode ser alterado manualmente para que na busca alcance o último elemento do vetor
        //min += 58;
        //max += 95;
        min += alcance_min(tam_lista);
        max += alcance_max(tam_lista);
        //cout << "Buscando o número: " << x << endl;
        auto inicio_binaria = chrono::steady_clock::now();
        pos = busca_binaria(x, lista, tam_lista);
        auto final_binaria = chrono::steady_clock::now();;

        //cout << pos << endl;
        auto time = chrono::duration_cast<chrono::nanoseconds>(final_binaria - inicio_binaria).count();
        time_total_binaria += time;
        //cout << "Time = " << time << endl;
    }
    //cout << "Buscando o número: " << x << endl;
    cout << "Time Total Binaria= " << time_total_binaria << endl;
    cout << "Media Binaria = " << (time_total_binaria / 30) << endl;
    
    
    return 0;
}

int alcance_min(int tam_vetor){
    int min;
    if(tam_vetor <= 10){
        min = 3;
    }  
    else if(tam_vetor > 10 && tam_vetor<= 20){
        min = 5;
    }
    else if(tam_vetor > 20 && tam_vetor<= 50){
        min = 9;
    }
    else if(tam_vetor > 50 && tam_vetor<= 100){
        min = 18;
    }
    else if(tam_vetor > 100 && tam_vetor<= 150){
        min = 27;
    }
    else if(tam_vetor > 150 && tam_vetor<= 200){
        min = 35;
    }
    else if(tam_vetor > 200 && tam_vetor<= 250){
        min = 42;
    }
    else if(tam_vetor > 250 && tam_vetor<= 300){
        min = 59;
    }
    else if(tam_vetor > 300 && tam_vetor<= 350){
        min = 63;
    }
    else if(tam_vetor > 350 && tam_vetor<= 400){
        min = 69;
    }
    else if(tam_vetor > 400 && tam_vetor<= 600){
        min = 76;
    }
    else if(tam_vetor > 600 && tam_vetor<= 800){
        min = 81;
    }
    else if(tam_vetor > 800 && tam_vetor<= 1000){
        min = 90;
    }
    else if(tam_vetor > 1000 && tam_vetor<= 1500){
        min = 103;
    }
    else if(tam_vetor > 1500 && tam_vetor<= 2000){
        min = 110;
    }
    else if(tam_vetor > 2000 && tam_vetor<= 2500){
        min = 119;
    }
    else if(tam_vetor > 2500 && tam_vetor<= 3000){
        min = 153;
    }
    else{
        min = 186;
    }
    return min;
}
int alcance_max(int tam_vetor){
    int max;
    if(tam_vetor <= 10){
        max = 5;
    }  
    else if(tam_vetor > 10 && tam_vetor<= 20){
        max = 9;
    }
    else if(tam_vetor > 20 && tam_vetor<= 50){
        max = 17;
    }
    else if(tam_vetor > 50 && tam_vetor<= 100){
        max = 31;
    }
    else if(tam_vetor > 100 && tam_vetor<= 150){
        max = 69;
    }
    else if(tam_vetor > 150 && tam_vetor<= 200){
        max = 79;
    }
    else if(tam_vetor > 200 && tam_vetor<= 250){
        max = 83;
    }
    else if(tam_vetor > 250 && tam_vetor<= 300){
        max = 96;
    }
    else if(tam_vetor > 300 && tam_vetor<= 350){
        max = 105;
    }
    else if(tam_vetor > 350 && tam_vetor<= 400){
        max = 118;
    }
    else if(tam_vetor > 400 && tam_vetor<= 600){
        max = 127;
    }
    else if(tam_vetor > 600 && tam_vetor<= 800){
        max = 138;
    }
    else if(tam_vetor > 800 && tam_vetor<= 1000){
        max = 145;
    }
    else if(tam_vetor > 1000 && tam_vetor<= 1500){
        max = 156;
    }
    else if(tam_vetor > 1500 && tam_vetor<= 2000){
        max = 172;
    }
    else if(tam_vetor > 2000 && tam_vetor<= 2500){
        max = 189;
    }
    else if(tam_vetor > 2500 && tam_vetor<= 3000){
        max = 200;
    }
    else{
        max = 250;
    }
    return max;
}