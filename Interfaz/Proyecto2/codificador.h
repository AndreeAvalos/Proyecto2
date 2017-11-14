#ifndef CODIFICADOR_H
#define CODIFICADOR_H
#include <QString>

using namespace std;

struct Codificador{

    int getCodigo(QString palabra){

        string str = palabra.toStdString();
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);

        int resultado=0;

        //qInfo()<<str.length();
        for(int i=0; i<str.length();i++){
            //qInfo()<<str[i];
            switch (str[i]) {
            case 'a':
                resultado+=1;
                break;
            case 'b':
                resultado+=2;
                break;
            case 'c':
                resultado+=3;
                break;
            case 'd':
                resultado+=4;
                break;
            case 'e':
                resultado+=5;
                break;
            case 'f':
                resultado+=6;
                break;
            case 'g':
                resultado+=6;
                break;
            case 'h':
                resultado+=8;
                break;
            case 'i':
                resultado+=9;
                break;
            case 'j':
                resultado+=10;
                break;
            case 'k':
                resultado+=11;
                break;
            case 'l':
                resultado+=12;
                break;
            case 'm':
                resultado+=13;
                break;
            case 'n':
                resultado+=14;
                break;
            case 'o':
                resultado+=15;
                break;
            case 'p':
                resultado+=16;
                break;
            case 'q':
                resultado+=17;
                break;
            case 'r':
                resultado+=18;
                break;
            case 's':
                resultado+=19;
                break;
            case 't':
                resultado+=20;
                break;
            case 'u':
                resultado+=21;
                break;
            case 'v':
                resultado+=22;
                break;
            case 'w':
                resultado+=23;
                break;
            case 'x':
                resultado+=24;
                break;
            case 'y':
                resultado+=25;
                break;
            case 'z':
                resultado+=26;
                break;
            default:
                break;
            }
        }
        //qInfo()<<"palabra a codificar "<<QString::fromStdString(str)<<" palabra codificada: "<<QString::fromStdString(resultado);
        //qInfo()<<resultado;
        return  resultado;
    }
};
#endif // CODIFICADOR_H
