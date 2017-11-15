#include "tablahash.h"
#include "listadoble.h"

//Constructor del nodo
Nodo::Nodo(int id, Donacion *valor)
{
    this->id = id;
    this->lst = new ListaDoble();
    lst->agregar(valor);
}

//Constructor de la tabla hash
TablaHash::TablaHash(int TAMTABLA)
{
    this->TAMTABLA = TAMTABLA; // tamanio de la tabla
    Tabla = new Nodo*[TAMTABLA]; // Reserva la cantidad de posiciones de memorias a utilizar
    for(int i = 0; i < TAMTABLA; i++)
    {
        Tabla[i] = 0; // inicializar todas las posiciones de la tabla en null
    }
    numElementos = 0; // numero de elemntos
    factorCarga = 0; // el factor de carga empieza en cero
}

bool TablaHash::existe(int id)
{
    int posicion = posicionTabla(id); // obtiene la posicion del identificador
    Nodo *actual = Tabla[posicion]; // obtiene la posicion de memoria si el identificador ya fue insertado
    if(actual) // si actual no es vacio
    {
        if(actual->eliminado) // verifica si ya fue insertado y eliminado
            return false; // si fue eliminado, retornar falso, esto es por si se quiere insertar nuevamente el identificador a la tabla
        else
            return true; // si no fue eliminado, entonces existe
    }
    else
    {
        return false; // si la posicion de la tabla es nulo, entonces no existe elemento
    }
}

void TablaHash::insertar(int id, Donacion *valor)
{
    if(!existe(id)) // verifica si el elemento ya fue insertado
    {
        Nodo * nuevo = new Nodo(id, valor); // crea un nuevo nodo
        int posicion = posicionTabla(id); // busca en que posicion ponerlo
        Tabla[posicion] = nuevo;
        Tabla[posicion]->eliminado = false;
        numElementos++;
        factorCarga = (double)(numElementos)/TAMTABLA; // actualiza el factor de carga
        if(factorCarga > 0.55) // si el factor de carga excede el 55% hacer rehashing, el factor de carga puede ser cualquiera
            rehashing(TAMTABLA);
    }else if(existe(id)==true){
        ListaDoble *lst = getDonacion(id);
        if(lst->existe(valor->nombre)==false){
            lst->agregar(valor);
        }else{
            lst->getDonacion(valor->nombre,valor->unidades);
        }
    }
}

void TablaHash::borrar(int id)
{
    if(existe(id)) //busca si existe entonces borrar
    {
        int posicion = posicionTabla(id); // busca la posicion donde se encuentra
        //Tabla[posicion]->lst =NULL; // asigna el valor a vacio
        //Tabla[posicion]->eliminado = true; // cambiar variable eliminado, para indicar que ya no esta en la tabla
        Tabla[posicion]=NULL;
    }
}

QString TablaHash::imprimir()
{
    QString result;

    for(int i = 0; i < TAMTABLA; i++)
    {
        if(Tabla[i]){
           // qInfo()<<"-------------------------" <<QString::number(Tabla[i]->id) << " --------------------------- ";
            result+="-------------"+QString::number(Tabla[i]->id)+"-------------\n";
            result+=Tabla[i]->lst->imprimir();
            //Tabla[i]->lst->size;
        }else
            //qInfo()<< "------------------------- NULL ---------------------------";
            result+= "-------------NULL-------------\n";
    }
    return result;
}

int TablaHash::getTamTabla()
{
    return TAMTABLA;
}

bool TablaHash::eliminar(int id, QString nombre)
{
    if(existe(id)){
        if(getDonacion(id)->existe(nombre)==true){
            return getDonacion(id)->borrar(nombre);
        }else
            return false;
    }
    return false;

}

void TablaHash::graficarTabla()
{
    //Abrir el documento
        std:: ofstream ficheroSalida;
         ficheroSalida.open ("/home/andree/Escritorio/EDDArchivos/TablaHash.txt");
         ficheroSalida << "digraph{ bgcolor = gray \n node[fontcolor = \"white \", height = 0.5, color = \"white \"] \n [shape=rect, style=filled, color=blue] \n rankdir=UD \n edge  [color=\"white\", dir=fordware]\n";
         int cont=0;
         int cont2=0;
        for(int i = 0; i < TAMTABLA; i++)
        {
            if(Tabla[i]){
                //std::cout << Tabla[i]->id << " ---- " << Tabla[i]->valor << std::end;
                if(cont==0){
                    //qInfo()<<"nel";
                    ficheroSalida<<'\"'<<QString::number(Tabla[i]->id).toStdString()<<'\"';
                }else
                    ficheroSalida<<"->"<<'\"'<<QString::number(Tabla[i]->id).toStdString()<<'\"';
                cont++;
            }
            cont2=i;
        }
        ficheroSalida<<";\n";

        if(cont2==TAMTABLA-1){
            //qInfo()<<"Que esta pasando aqui doctor garcia";
            for(int i = 0; i < TAMTABLA; i++)
            {
                if(Tabla[i]){
                    //std::cout << Tabla[i]->id << " ---- " << Tabla[i]->valor << std::end;
                    ListaDoble * lst = Tabla[i]->lst;
                    if(lst->first!=nullptr){
                        ficheroSalida<<'\"'<< QString::number(Tabla[i]->id).toStdString()<<'\"'<<"->"<<'\"'<<lst->first->getDato()->nombre.toStdString()<<'\"'<<";\n";
                        //qInfo()<<"entro aqui primero";
                        ficheroSalida<<lst->graficarLista().toStdString();
                    }
                }
            }
        }
        ficheroSalida<<";";
        ficheroSalida<<"}";
        ficheroSalida.close();
        int num = system("dot -Tpng /home/andree/Escritorio/EDDArchivos/TablaHash.txt -o /home/andree/Escritorio/EDDArchivos/TablaHash.png");
}

void TablaHash::Reduce_AND_Delete(int codigo, QString nombre, int unidades)
{
    //comprobamos si el dato existe
    if(existe(codigo)==true){
        //instanciamos la lista que contiene el nodo
        ListaDoble *lst = getDonacion(codigo);
        //verificamos si el nombre existe en la lista
        if(lst->existe(nombre)==true){
            //instanciamos el valor de la lista asociada al nombre
            Donacion *temp = lst->buscar(nombre);
            //comprobamos si el numero de unidades es mayor al numero de unidades disponibles
            if(temp->unidades>=unidades){
                //qInfo()<<"Unidades iniciales: "<<temp->unidades<<" Unidades a restar: "<<unidades;
                //le restamos las unidades
                temp->unidades= temp->unidades-unidades;

                //qInfo()<<"Restantes: "<<temp->unidades;
                //si las unidades es menor o igual a 0
                if(temp->unidades<=0){
                    //procedemos a eliminar el nodo en la lista
                    lst->borrar(nombre);
                }else{
                    return;
                }
            }
        }else
            return;

        //Si depues de borrar ya no existe ningun recurso entonces borrar espacio en tabla
        if(lst->first==nullptr){
            borrar(codigo);
        }

    }else
        return;
}

int TablaHash::posicionTabla(int id)
{
    //Aqui se implementa la funcion de dispercion
    int i = 0, p;
    p = id % TAMTABLA; // funcion de dispercion
    while(Tabla[p] && (Tabla[p])->id != id)
    {
        i++;
        p = (id % 7 + 1) * i;
        if(p > TAMTABLA)
            p = p -TAMTABLA;
    }
    return p;
}

int TablaHash::siguienteTam(int tam)
{
    // esta funcion busca el siguiente numero primo
    int a = 0;
    tam = tam + 1;
    for(int i = 1; i <= tam; i++)
    {
        if((tam) % i == 0)
            a++;
    }

    if(a == 2)
        return tam;
    else
        return siguienteTam(tam);
}

void TablaHash::rehashing(int tam)
{
    tam = siguienteTam(tam); //busca el nuevo tamanio
    TablaHash *nuevaTabla = new TablaHash(tam); // crea la nueva tabla
    for(int i = 0; i < TAMTABLA; i++)
    {
        ListaDoble *aux =Tabla[i]->lst;
        nodoD *temporal = aux->first;
        while(temporal!=nullptr){
            nuevaTabla->insertar(Tabla[i]->id, temporal->dato); // inserta los datos anteriores de la tabla en la nueva
            temporal= temporal->siguiente;
        }
    }
    TAMTABLA = tam; // cambiar tamanio
    numElementos = nuevaTabla->numElementos;
    factorCarga = nuevaTabla->factorCarga;
    delete[] this->Tabla; // borrar tabla anterior
    Tabla = nuevaTabla->Tabla;
}

ListaDoble* TablaHash::getDonacion(int id)
{

    for(int i = 0; i < TAMTABLA; i++)
    {
        if(Tabla[i])
        {
            if(Tabla[i]->id==id){
                return Tabla[i]->lst;
            }
        }

    }
    return NULL;

}
