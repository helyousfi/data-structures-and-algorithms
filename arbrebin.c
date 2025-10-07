/*	Module arbrebin.c	*/
#include <stdio.h>
#include <stdlib.h>
#include "arbrebin.h"

static char *nom_module = "arbre binaire";

typedef struct noeud {
	void *objet;
	struct noeud *gauche, *droite, *pere;
}*noeud;

struct csvg {
    noeud svue;
    struct csvg *sprec;
};

typedef struct tete {
	noeud racine, vue;
	struct csvg *svg;
}*arbrebin;

typedef enum{racine, pere, gauche, droite} direction;

/*	Fonction créer	*/
static arbrebin creer()
{
	arbrebin r;
    r = (arbrebin)malloc(sizeof(struct tete));
    r->racine = r->vue = NULL;
    r->svg = NULL;
    return r;
}

static void detruire_noeud_rec(noeud n, void (*det_obj)(void*))
{
	if(!n) return;
	
	detruire_noeud_rec(n->gauche, det_obj);
	detruire_noeud_rec(n->droite, det_obj);
	
	if(det_obj)
		det_obj(n->objet);
	
	free(n);
}

/* Fonction detruire */
static void detruire(arbrebin r, void (*det_obj)(void*))
{
	// Parcours en postordre
	if(!r) return;
	detruire_noeud_rec(r->racine, det_obj);
}

static void detruire_iter(arbrebin r, void (*det_obj)(void*))
{
	if (!r || !r->racine) return;
	
	noeud x;
	r->vue = r->racine;
	
	// Parcours en postordre
	while(r->vue)
	{
		while(r->vue->gauche) 
			r->vue = r->vue->gauche; 
		while(r->vue && r->vue->droite == NULL)
		{
			x = r->vue;
			noeud pere = x->pere;
			
			if (det_obj)
				(*det_obj)(x->objet);

			free(x);
			
			if(pere)
			{
				if(pere->droite == x)
					pere->droite = NULL;
				else
					pere->gauche = NULL;
			}
			else
			{
				r->vue = r->racine = NULL;
				return;
			}
			r->vue = pere; 
		}
		if(r->vue && r->vue->droite)
		{
			noeud tmp = r->vue->droite;		
			r->vue->droite = NULL;
			r->vue = tmp;
		}
	}
}

static void ERR_vue() {
	printf("ERREUR dans module %s.\n", nom_module);
}

static int aller(arbrebin r, direction d)
{
		switch(d)
		{
			case racine:
				r->vue = r->racine;
				return 1;
			case gauche:
				if(r->vue == NULL) {ERR_vue(); return 0;}
				if(r->vue->gauche) {r->vue = r->vue->gauche; return 1;}
				return 0;
			case droite:
				if(r->vue == NULL) {ERR_vue(); return 0;}
				if(r->vue->droite) {r->vue = r->vue->droite; return 1;}
				return 0;
			case pere:
				if(r->vue == NULL) {ERR_vue(); return 0;}
				if(r->vue->pere) {r->vue = r->vue->pere; return 1;}
				return 0;
			default:
				ERR_vue();
				return 0;
		}
}


/*	Procedure ajouter */
static void ajouter(arbrebin r, direction d, void *obj)
{
	noeud n = (noeud) malloc (sizeof(struct noeud));
	n->objet = obj;
	n->droite = n->gauche = NULL;
	switch(d)
	{
		case gauche:
			n->gauche = r->vue->gauche;
			r->vue->gauche = n;
			n->pere = r->vue;
			if(n->gauche)
				n->gauche->pere = n;
			r->vue = n;
			break;
		case droite:
			n->droite = r->vue->droite;
			r->vue->droite = n;
			n->pere = r->vue;
			if(n->droite)
				n->droite->pere = n;
			r->vue = n;
			break;
		case racine:
			r->vue = n;
			n->gauche = r->racine;
			if(r->racine) 
				r->racine->pere = n;
			r->racine = n;
			break;
		case pere:
			if(!r->vue->pere) r->racine = n;
			n->pere = r->vue->pere;
			r->vue->pere = n;
			n->gauche = r->vue;
			if(n->pere)
			{
				if(n->pere->gauche == r->vue)
					n->pere->gauche = n;
				else
					n->pere->droite = n;
			}
			r->vue = n;
			break;
	}
}


/* --- Interface publique du module --- */
struct {
	arbrebin (*creer)();
	void (*detruire) (arbrebin, void (*)(void*));
	void (*detruire_iter) (arbrebin, void (*)(void*));
	int (*existe)(arbrebin, direction);
	void *(*lire)(arbrebin);
	int (*aller)(arbrebin, direction);
	void (*ajouter)(arbrebin, direction, void *);
    int (*oter)(arbrebin, void (*)(void*));
    void (*remplacer)(arbrebin, void*, void (*)(void*));
    void (*fixer)(arbrebin, direction);
    int (*retablir)(arbrebin);
    void (*afficher)(arbrebin, void (*)(void*));
    void (*deplacer)(arbrebin, direction);
    void (*greffer)(arbrebin, arbrebin, direction);
    arbrebin (*tailler)(arbrebin, direction);
}Arbrebin = {
    .creer = creer,
    .detruire = detruire,
    .detruire_iter = detruire_iter,
    .aller = aller,
    .ajouter = ajouter,
};

int main(void)
{
	printf("%s", nom_module);
    arbrebin arbre = Arbrebin.creer();
    
    /* Your tests here */
    
    Arbrebin.detruire(arbre, NULL);
    return 0;
}
