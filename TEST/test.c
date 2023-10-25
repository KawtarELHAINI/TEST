
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct date{
	int jour;
	int mois;
	int annee;
}date;

typedef struct task{
	int id;
	char titre[80];
	date deadline;
	char desc[200];
	char status[10];
}task;


int add (task todo[],int nbr)
      {
        int id = nbr + 1;
        todo[nbr].id = id;
		printf("titre de tache %d : ",nbr + 1);
		getchar();
		fgets(todo[nbr].titre, 80, stdin);
		todo[nbr].titre[strlen(todo[nbr].titre)-1] = '\0';

		printf("deadline de tache :%d (jour/mois/annee) ",nbr + 1);
		scanf("%d/%d/%d", &todo[nbr].deadline.jour, &todo[nbr].deadline.mois, &todo[nbr].deadline.annee);

		printf("description de tache:  %d : ",nbr+ 1);
		getchar();
		fgets(todo[nbr].desc, 200, stdin);
		todo[nbr].desc[strlen(todo[nbr].desc)-1] = '\0';

		printf("status de tache numero %d (todo,doing,done): ",nbr+1);
        scanf("%s", todo[nbr].status);

		return nbr + 1;
      }



int addmore(task todo[],int nbr)
 {
	int i;
	int nbrs;
	 printf("nombre de taches : ");
	 scanf("%d", &nbrs);

	 printf("ADD new tasks %d\n", nbrs);
	   i=0;
	while (i < nbrs)
  {
        nbr = add(todo,nbr);
        i++;
     printf("-----------------------------------------------------------------------------\n");
  }
	return nbr;
 }

void affichage(task todo[],int nbr)
   {
	  int i;
      for(i=0;i<nbr;i++)
       {
		    printf("Tach Numero : %d \n",i+1);
			printf("id de tache numero : %d \n", todo[i].id);
			printf("titre de tache numero : %s \n", todo[i].titre);
			printf("description de tache numero : %s \n", todo[i].desc);
			printf("deadline : %d-%d-%d\n", todo[i].deadline.jour, todo[i].deadline.mois, todo[i].deadline.annee);
			printf("status de tache numero (todo,doing,done): %s \n", todo[i].status);
			printf("---------------------------------------------------------------------------------\n");
	   }
   }

void trialp(int nbr, task t[])
{
    task alp;
    int i,j;
   for(i=0;i<nbr-1;i++)
    {
       for(j=i+1;j<nbr;j++)
        {
            if(strcmp(t[i].titre, t[j].titre) > 0)
            {
                alp = t[i];
                t[i] = t[j];
                t[j] = alp;
            }
        }
    }
}


void modifytaskdescription(int id, int nbrs, task tasks[])
  {
        int i;
        for (int i = 0; i < nbrs; i++)
    {
            if (tasks[i].id == id)
        {
            printf("Entrez la nouvelle description pour la tache %d : ", id);
            getchar();
            fgets(tasks[i].desc, 200, stdin);
            tasks[i].desc[strlen(tasks[i].desc)-1] = '\0';

            printf("Description change avec succes :) \n");
            return;
        }
    }
        printf("la tache avec l'identifiant %d n'existe pas!!.\n", id);
  }

void modifyStatutTasks(int id, int nbrs, task tasks[])
  {
       for (int i = 0; i < nbrs; i++)
        {
             if (tasks[i].id == id)
           {
             printf("Entrez le nouveau statut pour la tache %d (todo,doing,done): ", id);
            getchar();
            fgets(tasks[i].status, 10, stdin);
            tasks[i].status[strlen(tasks[i].status)-1] = '\0';

            printf("Statut changer avec succes :)\n");
             return;
           }
        }
        printf("Aucune tache avec l'identifiant %d n'a ete trouvee!\n", id);
  }

void modifiyDeadlineTask(int id, int nbrs, task tasks[])
{
      for (int i = 0; i < nbrs; i++)
   {
        if (tasks[i].id == id)
     {
            printf("Entrez la nouvelle deadline pour la tache %d (jour/mois/annee): ", id);
            scanf("%d/%d/%d", &tasks[i].deadline.jour, &tasks[i].deadline.mois, &tasks[i].deadline.annee);

            printf("Deadline changer avec succes :)\n");
            return;
     }
   }
     printf("Aucune tache avec l'identifiant %d n'a été trouvée!\n", id);
}

int deleteTask(int id, int nbr, task tasks[])
 {
        int found = 0;
        for (int i = 0; i < nbr; i++)
    {
        if (tasks[i].id == id)
        {
            found = 1;
            for (int j = i; j < nbr - 1; j++)
            {
                tasks[j] = tasks[j + 1];
            }
            printf("Tache avec l'identifiant %d supprimée avec succès.\n", id);
            nbr--;
            break;
        }
    }
       if (!found)
       {
        printf("Aucune tache avec l'identifiant %d n'a été trouvée!\n", id);
       }
    return nbr;
 }

 int searchTaskById(int id, int nbr, task tasks[]) {
    int found = 0;
    for (int i = 0; i < nbr; i++) {
        if (tasks[i].id == id) {
            printf("Tache avec l'identifiant %d :\n", id);
            printf("id de tache : %d\n", tasks[i].id);
            printf("titre de tache : %s\n", tasks[i].titre);
            printf("description de tache : %s\n", tasks[i].desc);
            printf("deadline : %d-%d-%d\n", tasks[i].deadline.jour, tasks[i].deadline.mois, tasks[i].deadline.annee);
            printf("statut de tache : %s\n", tasks[i].status);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Aucune tache avec l'identifiant %d n'a ete trouvee!\n", id);
    }
    return found;
}

int searchTaskByTitle( char title[], int nbr, task tasks[]) {
    int found = 0;
    for (int i = 0; i < nbr; i++) {
        if (strcmp(tasks[i].titre, title) == 0) {
            found = 1;
            printf("id de tache : %d\n", tasks[i].id);
            printf("titre de tache : %s\n", tasks[i].titre);
            printf("description de tache : %s\n", tasks[i].desc);
            printf("deadline : %d-%d-%d\n", tasks[i].deadline.jour, tasks[i].deadline.mois, tasks[i].deadline.annee);
            printf("statut de tache : %s\n", tasks[i].status);
        }
    }
    if (!found) {
        printf("Aucune tache avec le titre '%s' n'a été trouvée!\n", title);
    }
    return found;
}


 void trierparDeadline(task todo[], int nbr) {
    for (int i = 0; i < nbr; i++) {
        for (int j = 0; j < nbr - i - 1; j++) {
            if (todo[j].deadline.annee > todo[j + 1].deadline.annee ||
                (todo[j].deadline.annee == todo[j + 1].deadline.annee && todo[j].deadline.mois > todo[j + 1].deadline.mois) ||
                (todo[j].deadline.annee == todo[j + 1].deadline.annee && todo[j].deadline.mois == todo[j + 1].deadline.mois && todo[j].deadline.jour > todo[j + 1].deadline.jour)) {
                task temp;
                temp = todo[j];
                todo[j] = todo[j + 1];
                todo[j + 1] = temp;
            }
        }
    }
}







int nombreTachesCompletes(int nbr, task todo[]) {
    int count = 0;
    for (int i = 0; i < nbr; i++) {
        if (strcmp(todo[i].status, "done") == 0) {
            count++;
        }
    }
    return count;
}

 int nombreTachesIncompletes(int nbr, task todo[]) {
    int count = 0;
    for (int i = 0; i < nbr; i++) {
        if (strcmp(todo[i].status, "todo") == 0 || strcmp(todo[i].status, "doing") == 0) {
            count++;
        }
    }
    return count;
}

void afficherJoursRestants(task todo[], int nbr) {
    date currentDate;
    currentDate.jour = 26;  
    currentDate.mois = 9;   
    currentDate.annee = 2023;  

    printf(" Jours restants pour chaque tache :\n");
    for (int i = 0; i < nbr; i++) {
        int joursRestants = 0;
        if (todo[i].deadline.annee > currentDate.annee ||
            (todo[i].deadline.annee == currentDate.annee && todo[i].deadline.mois > currentDate.mois) ||
            (todo[i].deadline.annee == currentDate.annee && todo[i].deadline.mois == currentDate.mois && todo[i].deadline.jour >= currentDate.jour)) {
            joursRestants = (todo[i].deadline.annee - currentDate.annee) * 365 +(todo[i].deadline.mois - currentDate.mois) * 30 + (todo[i].deadline.jour - currentDate.jour);
        }
        printf("Tache : %s, Jours restants jusqu'au delai : %d \n", todo[i].titre, joursRestants);
    }
   return ;
}

void afficherStatistiques(int nbr, task todo[]) {
    printf("Nombre total de taches : %d\n", nbr);

    int completes = nombreTachesCompletes(nbr, todo);
    int incompletes = nombreTachesIncompletes(nbr, todo);

    printf("Nombre de taches completes : %d\n", completes);
    printf("Nombre de taches incompletes : %d\n", incompletes);

    date currentDate;
    currentDate.jour = 25;  // Replace with the current day
    currentDate.mois = 9;   // Replace with the current month
    currentDate.annee = 2023;  // Replace with the current year

    for (int i = 0; i < nbr; i++) {
        int joursRestants = 0;
        if (todo[i].deadline.annee > currentDate.annee ||
            (todo[i].deadline.annee == currentDate.annee && todo[i].deadline.mois > currentDate.mois) ||
            (todo[i].deadline.annee == currentDate.annee && todo[i].deadline.mois == currentDate.mois && todo[i].deadline.jour >= currentDate.jour)) {
            joursRestants = (todo[i].deadline.annee - currentDate.annee) * 365 +
                            (todo[i].deadline.mois - currentDate.mois) * 30 +
                            (todo[i].deadline.jour - currentDate.jour);
        }

    }
}






 int main(){
	   int nbr=0;
	   task todo[100];
       int choix;
       int id;
       int c;
    while(1)
    {
        printf(" ~~~~~~~~~~~~~~~~~~~~Menu de taches:~~~~~~~~~~~~~~~~~~~~~~ \n");
        printf("|1: Ajouter une nouvelle tache:                           |\n");
        printf("|2: Ajouter plusieurs nouvelles taches:                   |\n");
        printf("|3: Afficher la liste de toutes les taches                |\n");
        printf("|4: modifier la description d'une tache                   |\n");
        printf("|5: Supprimer une tache par identifiant                   |\n");
        printf("|6: Rechercher les Taches                                 |\n");
        printf("|7: Statistiques                                          |\n");
        printf("|8: trier alphabetiquement les taches                     |\n");
        printf("|9: trier par deadline                                    |\n");
        printf("|10: afficher les taches avec troix jours restant au moins|\n ");
        printf("|0: Fin du programme                                     |\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Entrer votre choix : ");
	     scanf("%d",&choix);
		switch(choix){
    	case 1 :
    		printf("Ajouter une nouvelle tache \n");
    		nbr = add(todo,nbr);
    		break;
    	case 2:
    		printf("Ajouter plusieurs nouvelles taches \n");
    		nbr = addmore(todo,nbr);
    		break;
    	case 3:
    		printf("Afficher la liste de toutes les taches \n");
    		affichage(todo,nbr);
    		break;
       case 4:
            printf("id :");
            scanf("%d", &id);
            printf("1: desc                                                  \n");
            printf("2: status                                                \n");
            printf("3: deadline                                              \n");
            printf("0: Fin du programme                                      \n");
            printf(" choice : ");
            scanf("%d", &c);

            if (c == 1)
                modifytaskdescription(id, nbr, todo);
            else if (c == 2)
                modifyStatutTasks(id, nbr, todo);
            else if (c == 3)
                modifiyDeadlineTask(id, nbr, todo);
            break;
       case 5:
            printf("Supprimer une tache par identifiant \n");
            printf("Entrez l'identifiant de la tache à supprimer : ");
            scanf("%d", &id);
            nbr = deleteTask(id, nbr, todo);
            break;
      case 6:
               printf("Rechercher une tache \n");
                printf("1-id :\n");
                printf("2-titre \n");
                printf("0: Fin du programme  \n");
                printf(" choice : ");
                scanf("%d", &c);

                if (c == 1) {
                    printf("Entrez l'identifiant de la tache : ");
                    scanf("%d", &id);
                    searchTaskById(id, nbr, todo);
                } else if (c == 2) {
                    char title[80];
                    printf("Entrez le titre de la tache : ");
                    getchar();
                    fgets(title, 80, stdin);
                    title[strlen(title) - 1] = '\0';
                    searchTaskByTitle(title, nbr, todo);
                }
                break;
      case 7:
        printf("Afficher les statistiques\n");
                afficherStatistiques(nbr, todo);
                 afficherJoursRestants(todo, nbr);
            break;
      case 8:
            printf("trier alphabetiquement \n");
            trialp(nbr, todo);
            break;


      case 9:
            printf("Trier par deadline\n");
            trierparDeadline(todo, nbr);
            printf("Taches triees avec succes :)\n");
            break;
   case 10:
    if (nbr != 0) {
        printf("Taches avec moins de 3 jours restants avant la deadline :\n");
        for (int i = 0; i < nbr; i++) {  
            int days_remaining = (todo[i].deadline.annee - 2023) +
                                 (todo[i].deadline.mois - 9) +
                                 (todo[i].deadline.jour - 25);
            if (days_remaining <= 3 && days_remaining >= 0) {
                printf("ID : %d\n", todo[i].id);
                printf("Titre : %s\n", todo[i].titre);
                printf("Description : %s\n", todo[i].desc);
                printf("Statut : %s\n", todo[i].status);
                printf("Deadline : %d/%d/%d\n", todo[i].deadline.jour, todo[i].deadline.mois, todo[i].deadline.annee);
            }
        }
    } else {
        printf("Il n'y a aucune tache pour l'instant.\n");
    }
    break;


           case 0:
    	     printf("Au revoir !");
    	    return 0;
       default:
		     printf("Choix invalide. Veuillez reessayer! \n");

     	}
    }
 printf("%d",nbr);

    return 0;
    }









