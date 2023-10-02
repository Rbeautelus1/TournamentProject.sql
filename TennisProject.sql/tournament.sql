Create database tournament;

Create table PlayerInfo(
  Player_Id int not null unique, Fname char(30), Lname char(45), Country char(45), Academy char(50), Sponsor char(20)
  Primary Key (Player_Id)
);
Create table Racket (
  Sponsor char(20), StringType char(20), NameofRacket char(20), Size varchar(8) Primary Key(Sponsor)
);

Create table Rank (
  Player_Id int not null  unique, national varchar(5), international varchar(5), state varchar(5), Primary Key(Player_Id)
);

Create table Record(
  Player_Id int not null unique, Wins int, Losses int, Forfeits int, Primary Key(Player_Id)
);

Insert into PlayerInfo values("1","Carlos","Alcaraz","Spain","Equilte Academy","Nike");
Insert into PlayerInfo values("2", "Rogert", "Federer","Sweden","Biel Academy","Uniqlo");
Insert into PlayerInfo values("3", "Casper", "Ruud","Denmark","Nadal Academy","Fila");
Insert into PlayerInfo values("4", "Taylor", "Fritz","United States","Turin Academy","Lacoste");
Insert into PlayerInfo values("5", "Nick", "Kyrigos","Australia","Canberra Academy","Addidas");

Insert into Racket values("Addidas", "Lexilon", "Wilson","98 in");
Insert into Racket values("Fila", "Synthetic Gut", "Head","95 in");
Insert into Racket values("Lacoste", "Wilson NXT", "Technifibre","95 in");
Insert into Racket values("Nike", "Lexilon", "Babolat","93 in");
Insert into Racket values("Uniqlo", "Synthetic Gut", "Wilson","97 in");

Insert into Rank values("1", "#5", "#3","#1");
Insert into Rank values("2", "#15", "#30","#11");
Insert into Rank values("3", "#10", "#6","#2");
Insert into Rank values("4", "#60", "#100","#40");
Insert into Rank values("5", "#45", "#29","#22");

Insert into Record values("1", "90", "31","5");
Insert into Record values("2", "1251", "275","8");
Insert into Record values("3", "170", "92","2");
Insert into Record values("4", "177", "144","10");
Insert into Record values("5", "205", "113","15");