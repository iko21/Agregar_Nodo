#include "Lista.h"

Lista::Lista()
{
    inicio=NULL;
}

Lista::~Lista()
{
    //dtor
}

void Lista::imprimir()
{
    for(Nodo*temp=inicio;
        temp!=NULL;
        temp=temp->sig)
        cout<<temp->num<<endl;
}

void Lista::agregarNodo(Nodo*n)
{
    if(inicio==NULL)
    {
        inicio=n;
    }else
    {
        Nodo*temp;
        for(temp=inicio;
            temp->sig!=NULL;
            temp=temp->sig);
            temp->sig=n;
    }
}
    void Lista:: borrarUltimo()
    {
        if(inicio==NULL)
        {
            return;
        }
        if(inicio->sig==NULL)
        {
            delete inicio;
            inicio=NULL;
            return;
        }

           Nodo*temp;
           for(temp=inicio;
           temp->sig->sig!=NULL;
           temp=temp->sig);

           delete temp->sig;
           temp->sig=NULL;

    }

 bool Lista:: agregarNodo(Nodo*n, int pos)
    {

            if(pos==0)
            {
                if(inicio==NULL)
                {
                    inicio=n;
                    return true;
                }else
                {
                    n->sig=inicio;
                    inicio=n;
                    return true;
                }
            }


        Nodo*temp;
        int i=0;
        for(temp=inicio;
            temp!=NULL;
            temp=temp->sig)
            {
                if(i==pos-1)
                {
                    n->sig=temp->sig;
                    temp->sig=n;
                    return true;
                }
                i++;
            }
            return true;
    }

    bool Lista::borrarNodo(int pos)
    {
        Nodo*temp;
        if(pos==0)
        {
            Nodo*temp=inicio->sig;
            inicio=inicio->sig;
            delete temp;
            return true;
        }
        int i=0;
        for(temp=inicio;
            temp!=NULL && i<pos-1;
            temp=temp->sig)
            {
                i++;
            }
                if(temp!=NULL)
                {
                    Nodo*t2=temp->sig->sig;
                    delete temp->sig;
                    temp->sig=t2;
                    return true;
                }else
                {
                    return false;
                }

    }

