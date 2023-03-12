/***************************************************************/
/*                                                             */
/*    M�dulo en C para uso de objetos en una estructura de     */
/*                                                             */
/*                   CONJUNTOS DISJUNTOS                       */
/*                                                             */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "disjoint.h"

/********************************************************/

disjoint disjoint_nuev(int n) {

	disjoint r;
	int i;

	if (!(r=(int*)malloc(sizeof(int)*n))) {
		fprintf(stderr,"disjoint_nuev: no hay memoria.\n");
		exit(1);
	}
	for (i=0;i<n;i++){
        r[i]=-1;
    }
	return(r);
}

/********************************************************/

void disjoint_dest(disjoint *c) {

	if (*c) {
		free(*c);
		*c=NULL;
	}
}

/********************************************************/

void disjoint_merge(disjoint c, int a, int b) {

	if (c[a]==c[b]) {
		c[a]=-1; //todo Esta mal ? Indicamos que la raíz está en a
		c[b]=a;
	}
	else if (c[a]<c[b]) c[b]=a;
	else c[a]=b;
}

/********************************************************/

int disjoint_find(disjoint c, int x) {

	int r,i;

	r=x;
	while (c[r]>0) r=c[r];
    // r es la raiz del árbol
	i=x;
    //Comprensión de caminos
	while (i!=r) {
		x=c[i];
		c[i]=r;
		i=x;
	}
	return(r);
}

/********************************************************/

void disjoint_printf(disjoint c,int n) {

	int i;

	for (i=0;i<n;i++) printf("%d ",c[i]);
	printf("\n");
	
}

