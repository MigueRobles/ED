//Practica final, idea;

void insertarhijoizqda(celdaarbolgeneral *t1, celdaarbolgeneral *n,celdaarbolgeneral *t2){
  if(t2!=0){
  t2->hermanodrcha=n->hizqda;
  t2->padre=n;
  n->hizqda = t2;
  t2 = 0;
  }
}

celdaarbolgeneral *podarhijoizda(celdaarbolgeneral *t, celdarbolgeneral *n){ //guardar el arbol en un parametro y no en res;
  celdaarbolgeneral *res =0;
  if(n->hizqda !=0){
    res =n->hizda;
    n->hizqda = res ->hermanodrcha;
    res->padre = res->hermanodrcha = 0;
  }
  return res;
}

void insertarhermanodrcha((celdaarbolgeneral *t1, celdaarbolgeneral *n,celdaarbolgeneral *t2){
  if(t2!=0){
  t2->hermanodrcha=n->hermanoderecha;
  t2->padre=n->padre;
  n->hermanodercha = t2;
  t2 = 0;
}

celdaarbolgeneral *podarhermanoderecha(celdaarbolgeneral *t, celdarbolgeneral *n){ //guardar el arbol en un parametro y no en res;
  celdaarbolgeneral *res =0;
  if(n->hermanoderecha !=0){
    res =n->hermanoderecha;
    n->hermanoderecha = res ->hermanodrcha;
    res->padre = res->hermanodrcha = 0;
  }
  return res;
}

void listarpreorden(celdar arbolgeneral *t){
  if(t!=0){
    cout << t->etiqueta;
    for(celdaarbolgeneral *aux =t->hizda){
      ...
    }
  }
}

listarpostorden
numero nodos
destruir
