void Buscar_Coincidencias(float k, float error_prec,float marg,int error_ptos,float ben_ap,int n_ptos,int pos,int *ptos_coincidentes,int *n_coincidencias,T_MOMENTO datos[N])
/*Devuelve el vector ptos_coincidentes, que contiene las posiciones de los puntos coincidentes encontrados
 * Devuelve por referencia el número de puntos hallados*/
{
     int i,j,cont;
     T_MOMENTO aux1,aux2,aux_pto,pto;
    
     
     *n_coincidencias=0;
     //pto=Momento(pos,pf);
     //pto = datos[pos];
	 pto.extremo = datos[pos].extremo;
	 pto.pos = datos[pos].pos;
	 pto.prec = datos[pos].prec;
	 
	 //printf("\n\n%d-%.2f-%d\n\n", pto.extremo, pto.prec, pto.pos);
	 
     for(i=n_ptos;i<TAM-n_ptos;i++)
     //for(i=n_ptos;i<pos-n_ptos;i++)
     {
        //aux1=Momento(pos-i,pf);
        //aux1 = datos[pos-i];
        aux1.extremo = datos[pos-i].extremo;
        aux1.pos = datos[pos-i].pos;
        aux1.prec = datos[pos-i].prec;
        
        if(aux1.prec > (pto.prec*(1-marg)) && aux1.prec<(pto.prec*(1+marg)) && aux1.extremo==pto.extremo)
        {
            //printf("\nPosible coincidencia");
            cont=0;
            for(j=1;j<=n_ptos;j++)
            {
                //aux_pto=Momento(pos-j,pf);
                //aux_pto = datos[pos-j];
                aux_pto.extremo = datos[pos-j].extremo;
                aux_pto.pos = datos[pos-j].pos;
                aux_pto.prec = datos[pos-j].prec;
                
                //aux2=Momento(pos-i-j,pf);
                //aux2 = datos[pos-i-j];
                aux2.extremo = datos[pos-i-j].extremo;
                aux2.pos = datos[pos-i-j].pos;
                aux2.prec = datos[pos-i-j].prec;
                
                if((aux1.prec/aux2.prec)>((pto.prec/aux_pto.prec)*(1-error_prec)) && (aux1.prec/aux2.prec)<((pto.prec/aux_pto.prec)*(1+error_prec)))
                {
                    //printf("\nNumero de puntos: %d",cont+1);
                    cont++;
                }
            }
            if(cont>(n_ptos-error_ptos))
            {
                ptos_coincidentes[*n_coincidencias]=aux1.pos;
                *n_coincidencias+=1;
                //printf("Coincidencias: %d",*n_coincidencias);
            }
        }
     }
}

