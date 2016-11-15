#include "distloc.h"

extern void escribeSalida(void);

extern const double RT;
extern PLocalidad ploc;
extern int cantiloc;

void escribeSalida(void){

  FILE * fh;
  int i,j;

  int e,m,l;

  fh=fopen("./salida.txt","w");
  for(i=0;i<cantiloc;i++){
    PLocalidad p=(ploc+i);

    for(j=0;j<23;j++){
      e=(int)(p->c[j]/1000000);
      m=(int)((p->c[j]-e*1000000)/1000);
      l=p->c[j]-e*1000000-m*1000;
      fprintf(fh,"%d,%d,%d,%d,%lf,%d,%d,%d,0\n",p->est,p->mun,p->loc,j,RT*p->dist[j],e,m,l);
    }

  }

  fclose(fh);

}
