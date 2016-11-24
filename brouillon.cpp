//generation du terrain

p:point aleatoire 

creearbre(point p,terrain** T)
{
	int r=alea(3,6);
	int i,j;
	for(i=p.getx()-r;i<2r+1;i++)
	{
		for(j=p.gety()-r;j<2r+1;j++)
		{
			if(i*i+j*j-r*r<=0	/*test si le carré est dans le cercle*/
			&& i>0 && j>0				
			&& i<W && j<H	/*test si le carré ne deborde pas de l'ecran*/
			&& T[i][j]==null)/*test si la case est nulle*/
				T[i][j]=new terrain('a',false,resarbre);
		}
	}
}

// attention le carré généré par p doit etre entierement dans le terrain
creerocher(point p,terrain** T)
{
	int taille n=alea(30,200);
	int[n][n] ttmp;
	int vrand;
	liste l;
	point destr,ptmp;
	
	//initialisation du tableau
	for(int i=0; i < n ; i++)
    {
        for(int j=0; j < n ; j++)
        {
            T[i][j]=1;
        }
    }
	
	for(int i=0; i < 3 ; i++)
	{
		
		//determine les coordonnées du point initialement détruit
		vrand=alea(4);
		switch(vrand)
		{
			case 1:
			destr.setx(0);
			destr.sety(alea(n))
			break;
			case 2:
			destr.setx(n-1)
			destr.sety(alea(n))
			break;
			case 3:
			destr.sety(0);
			destr.setx(alea(n))
			break;
			case 4:
			destr.sety(3-1)
			destr.setx(alea(n))
			break;
			default:
			cerr<<"erreur dans le case"<<endl;
			break;
		}
		
		T[destr.getx()][destr.gety()]=0;
		
		//detruit en cascade 1/9eme du roché crée
		for(int j=0;j<n/9;j++)
		{
			ptmp.setx(destr.getx());
			ptmp.sety(destr.gety());
			
			//4 test pour voir si l'on sort du tableau et que la case contient un "pixel " de rocher
			if(ttmp[destr.getx()+1<n &&destr.getx()+1][y=destr.gety()]==1)
			{
				ptmp.setx(ptmp.getx()+1);
				l.setsuiv(ptmp);
			}
			if(ttmp[destr.gety()+1<n && destr.getx()][y=destr.gety()+1]==1)
			{
				ptmp.sety(ptmp.gety()+1);
				l.setsuiv(ptmp);
			}
			if(ttmp[destr.getx()-1>0 && destr.getx()][y=destr.gety()-1]==1)
			{
				ptmp.sety(ptmp.gety()-1);
				l.setsuiv(ptmp);
			}
			if(ttmp[destr.getx()-1>0 && destr.getx()-1][y=destr.gety()]==1)
			{
				ptmp.setx(ptmp.getx()-1);
				l.setsuiv(ptmp);
			}
			
			vrand=alea(l.gettaille());
			for(k=0;k<vrand;k++){l=l->suiv}
			destr=l->getval();
			T[destr.getx()][destr.gety()]=0;
		}
	}
}