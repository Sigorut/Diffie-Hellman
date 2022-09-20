#include <QCoreApplication>
#include "krypto.h"
#include <QRandomGenerator>
#include <iostream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    long long i = QRandomGenerator::global()->bounded(1000000, 1000000000);
    long long p = 0, q = 0, g = 0, xa = 0, xb = 0, ya = 0, yb = 0, za = 0, zb = 0;
    for(; i > 100; i-- )
        if(is_prime_number(i)){
            if(is_prime_number((i*2)+1)){
            q = i;
            p = (q * 2)+1;
            break;
            }
        }
    do{
        g = QRandomGenerator::global()->bounded(2, p-2);
    }while(exp_mod(g,q,p)==1);
    qDebug() << "g = " << g <<" q = "<< q << " p = "<< p << " mod = " << exp_mod(g,q,p);
    qDebug("Input Xa Xb");
    std::cin >> xa >> xb;
    qDebug() << "xa = " << xa <<" xb = " << xb;
    ya = exp_mod(g, xa, p);
    yb = exp_mod(g, xb, p);
    qDebug() << "ya = " << ya <<" yb = " << yb;
    za = exp_mod(yb, xa, p);
    zb = exp_mod(ya, xb, p);
    qDebug() << "za = " << za <<" zb = " << zb;
    return a.exec();
}
