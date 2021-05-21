
void editp(int c)  //to edit persdetails
{
  ofstream ofl2("temp1.txt",ios::binary);
  if(!ofl2)
  cout<<"Error While Opening File";
  ifstream ifl4("PersonalDetails.txt",ios::binary);
  if(!ifl4)
  cout<<"Error While Opening File";
  ifl4.read((char*)&pob,sizeof(pob));
  while(!ifl4.eof())
  {
    if(pob.givecode()==c)
    {
      system("cls");
      cout<<"Please Enter the New details of the record"<<endl;
      pob.p_input(c);
      ofl2.write((char*)&pob,sizeof(pob));
      cout<<"\n\t\t\tModification Succesful!!!";
      ifl4.read((char*)&pob,sizeof(pob));
    }
    else
    {
      ofl2.write((char*)&pob,sizeof(pob));
      ifl4.read((char*)&pob,sizeof(pob));
    }
  }
  remove("PersonalDetails.txt");
  rename("temp1.txt","PersonalDetails.txt");
  ifl4.close();
  ofl2.close();
  getch();
}
void editt(int c)  //to edit travdetails
{
  ofstream ofl2("temp1.txt",ios::binary);
  if(!ofl2)
  cout<<"Error While Opening File";
  ifstream ifl4("TravelDetails.txt",ios::binary);
  if(!ifl4)
  cout<<"Error While Opening File";
  ifl4.read((char*)&tob,sizeof(tob));
  while(!ifl4.eof())
  {
    if(tob.gtcode()==c)
    {
      system("cls");
      cout<<"Please Enter the New details of the record"<<endl;
      tob.t_input(c);
      ofl2.write((char*)&tob,sizeof(tob));
      cout<<"\n\t\t\tModification Succesful!!!";
      ifl4.read((char*)&tob,sizeof(tob));
    }
    else
    {
      ofl2.write((char*)&tob,sizeof(tob));
      ifl4.read((char*)&tob,sizeof(tob));
    }
  }
  remove("TravelDetails.txt");
  rename("temp1.txt","TravelDetails.txt");
  ifl4.close();
  ofl2.close();
  getch();
}
void deletion(int c)  //common delete func()
{
  ofstream ofl2("temp1.txt",ios::binary);
  if(!ofl2)
  cout<<"Error While Opening File";
  ifstream ifl4("PersonalDetails.txt",ios::binary);
  if(!ifl4)
  cout<<"Error While Opening File";
  ifl4.read((char*)&pob,sizeof(pob));
  while(!ifl4.eof())
  {
    if(pob.givecode()!=c)
    {
      ofl2.write((char*)&pob,sizeof(pob));
    }
    ifl4.read((char*)&pob,sizeof(pob));
  }
  remove("PersonalDetails.txt");
  rename("temp1.txt","PersonalDetails.txt");
  ofl2.close();
  ifl4.close();
  ofstream ofl3("temp2.txt",ios::binary);
  if(!ofl3)
  cout<<"\nError While Opening File";
  ifstream ifl5("TravelDetails.txt",ios::binary);
  if(!ifl5)
  cout<<"\nError While Opening File";
  ifl5.read((char*)&tob,sizeof(tob));
  while(!ifl5.eof())
  {
    if(tob.gtcode()!=c)
    {
      ofl3.write((char*)&tob,sizeof(tob));
    }
    ifl5.read((char*)&tob,sizeof(tob));
  }
  ofl3.close();
  ifl5.close();
  remove("TravelDetails.txt");
  rename("temp1.txt","TravelDetails.txt");
  cout<<"\n\n\t\tDeletion Completed!";
  getch();
}

void main()
{
  system("cls");

  ifstream fl("INITIALL.txt",ios::binary); //initialisation of code
  if(!fl)
  cout<<"\nError";
  fl.read((char*)&code,sizeof(code));
  fl.close();
  int opt,opt1,opt2,opt3,opt4;
  int acceptcode,flag;
  getch();
  system("cls");
  do
  {
    system("cls");

    cout<<"\t\t MAIN MENU \n";
    cout<<"\n\t\t\tPlease select a kind of user:";
    cout<<"\n\n\t\t\t\t1.New User\n\n\t\t\t\t2.Existing User\n\n\t\t\t\t3.Exit";
    cout<<"\n\n\t\t\t\t ";
    cin>>opt;
    switch(opt)
    {
      case 1:do
	     {
	       system("cls");
	       cout<<"\n\n\n\t\t\t\t    NEW USER\n";
	       cout<<"\t\t\t\t    ****\n\n";
	       cout<<"\n\n\t\t\tChoose the type of details you want to enter:";
	       cout<<"\n\n\t\t\t\t1.Personal Details\n\n\t\t\t\t2.Travel Details\n\n\t\t\t\t3.Back\n\n\t\t\t\t ";
	       cin>>opt1;
	       switch(opt1)
	       {
                case 1:code++;
                pob.p_input(code);
                ofstream ofl("PersonalDetails.txt",ios::binary|ios::app);
                if(!ofl)
                cout<<"\n\n\t\tSorry.The File Cannot Be Opened For Writing"<<endl;
                ofl.write((char*)&pob,sizeof(pob));
                ofl.close();
                break;
                case 2:tob.t_input(code);
                ofstream ofl1("TravelDetails.txt",ios::binary|ios::app);
                if(!ofl1)
                cout<<"\n\n\t\tSorry.The File Cannot Be Opened For Writing"<<endl;
                ofl1.write((char*)&tob,sizeof(tob));
                ofl1.close();
                system("cls");
                cout<<"\n\n\n\n!!!!!Your Details Have Been Registered.Please Make A Note Of This Code: "<<code;
                cout<<"\n\n* For modifications,Please visit 'existing user' section in the main screen";
                getch();
                break;
	       }
	     }while(opt1!=3);
	     break;
      case 2:system("cls");
	     cout<<"\n\n\t\t\t** EXISTING USER **\n\n\t\tPlease Enter The Travel Code That Was Given To You\n\n\t\t\t ";
	     cin>>acceptcode;
	     if(acceptcode>code)
	     {
	       cout<<"\nNo such record has been created!";
	       break;
	     }
	     family(acceptcode,flag);
	     cout<<endl<<endl<<"\t\t\t\tCode no:"<<acceptcode;
	     getch();
	     if(flag==1)
	     {
	     do
	     {
	       system("cls");
	       cout<<"\n\n\t\t\t@@@@@@@@@ Information Centre @@@@@@@@@";
	       cout<<"\n\t\t\t\t  ~~~~~~~";
	       cout<<"\n\n\tPlease select the type of operation that you would like to perform:";
	       cout<<"\n\n\t\t\t1.View Personal Details\n\n\t\t\t2.View Travel Details\n\n\t\t\t3.Edit Details\n\n\t\t\t4.Compute Bill\n\n\t\t\t5.Back\n\n\t\t\t ";
	       cin>>opt2;
	       switch(opt2)
	       {
		 case 1:ifstream ifl("PersonalDetails.txt",ios::binary);
			if(!ifl)
			cout<<"\nError";
			ifl.read((char*)&pob,sizeof(pob));
			while(!ifl.eof())
			{
			  if(pob.givecode()==acceptcode)
			  {
			    break;
			  }
			  ifl.read((char*)&pob,sizeof(pob));
			}
			pob.p_output();
			ifl.close();
			break;
		 case 2:ifstream ifl1("TravelDetails.txt",ios::binary);
			if(!ifl1)
			cout<<"\nError";
			ifl1.read((char*)&tob,sizeof(tob));
			while(!ifl1.eof())
			{
			  if(tob.gtcode()==acceptcode)
			  {
			    break;
			  }
			  ifl1.read((char*)&tob,sizeof(tob));
			}
			tob.t_output();
			ifl1.close();
			break;
		 case 3:do
			{
			  system("cls");
			  cout<<"\n\n\n\t Edit Details ";
			  cout<<"\n\n\t\tPlease select from among the editing options:\n\n";
			  cout<<"\t\t\t\t1.Modify\n\n\t\t\t\t2.Delete\n\n\t\t\t\t3.Back\n\n\t\t\t\t ";
			  cin>>opt3;
			  switch(opt3)
			  {
			    case 1:do
				   {
				     system("cls");
				     cout<<"\n\n\t\t Modificaton \n";
				     cout<<"\t\t               ~~~~~";
				     cout<<"\n\n\tChoose The Type Of Details You Want To Modify:\n\n\t\t\t1.Personal Details\n\n\t\t\t2.Travel Details\n\n\t\t\t3.Back\n\n\t\t\t ";
				     cin>>opt4;
				     switch(opt4)
				     {
				       case 1:editp(acceptcode);
					      break;
				       case 2:editt(acceptcode);
					      break;
				       case 3:break;
				     }
				   }while(opt4!=3);
				   break;
			    case 2:deletion(acceptcode);
				   opt3=3;
				   opt2=5;
				   break;
			    case 3:break;
			  }
			}while(opt3!=3);
			break;
		 case 4:ifstream ifl3("PersonalDetails.txt",ios::binary);
			if(!ifl3)
			cout<<"\nError";
			ifl3.read((char*)&pob,sizeof(pob));
			while(!ifl3.eof())
			{
			  if(pob.givecode()==acceptcode)
			  {
			    break;
			  }
			  ifl3.read((char*)&pob,sizeof(pob));
			}
			ifstream ifl2("TravelDetails.txt",ios::binary);
			if(!ifl2)
			cout<<"\nError";
			ifl2.read((char*)&tob,sizeof(tob));
			while(!ifl2.eof())
			{
			  if(tob.gtcode()==acceptcode)
			  {
			    break;
			  }
			  ifl2.read((char*)&tob,sizeof(tob));
			}
			tob.accept(pob.give());
			tob.compute();
			ifl2.close();
			break;
		 case 5:break;
	       }
	     }while(opt2!=5);
	     }
	     break;
      case 3:ofstream fil("INITIALL.txt",ios::binary); //storing code value
	     if(!fil)
	     cout<<"\nError";
	     fil.write((char*)&code,sizeof(code));
	     fil.close();
	     system("cls");
	     cout<<"\n\n";
	     cout<<"	         ////_/  _/                            _/            \n";
	     cout<<"	            /      _///      _///  _//_/    _/  _/         \n";
	     cout<<"	           /      _/    _/  _/    _/  _/    _/  _//            \n";
	     cout<<"	          _/      _/    _/  _/    _/  _/    _/  _/  _/           \n";
	     cout<<"	         /      _/    _/    _//_/  _/    _/  _/    _/          \n";
	     cout<<"                                                                  \n";
	     cout<<"                                                                  \n";
	     cout<<"                                                                  \n";
	     cout<<"		         _/     _/                                       \n";
	     cout<<"		          /  _/    _//    _/    _/                     \n";
	     cout<<"		            _/    _/    _/  _/    _/                     \n";
	     cout<<"		            _/    _/    _/  _/    _/                     \n";
	     cout<<"		           /      _//      //_/                     \n\n";
             cout<<"\t    |===|						~~\n";
             cout<<"   	   |   |______________|| ||__	";
	     cout<<"\t\t    ||||\_()_()_()__()__()_()||||__/"<<endl;
	     cout<<"\t    `.==---------||----||-----||----||-----------------/"<<endl;
	     cout<<"\t      `.__________________/"<<endl;
	    // cout<<"..........oOoOo~~~~~~~~~~~~~~~~~~~~~~"<<endl;
//	     cout<<".........oOoOo~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  //	     cout<<".........oooo~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	     getch();
	     exit(0);
    }
    getch();
  }while(1); //infinite loop till exit selected
}