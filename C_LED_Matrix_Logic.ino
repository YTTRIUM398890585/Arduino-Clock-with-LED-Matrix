void MatrixLogic() {
  switch (Mat_Mode) {
    case 0:
      Matrix_Random_Off(); 
      break;
    case 1:
      Matrix_Hours_Minutes_Seconds_CentiSeconds();
      break;
    case 2:
      Matrix_Day_And_Date();
      break;
    case 3:
      animation_frame(0, 0, 0, 0, 0, 0, 0, 0,  //Creeper
                      0, 1, 1, 0, 0, 1, 1, 0,
                      0, 1, 1, 0, 0, 1, 1, 0,
                      0, 0, 0, 1, 1, 0, 0, 0,
                      0, 0, 1, 1, 1, 1, 0, 0,
                      0, 0, 1, 1, 1, 1, 0, 0,
                      0, 0, 1, 0, 0, 1, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0);
      break;
    case 4:
      animation_frame(0, 0, 0, 0, 0, 0, 0, 0,  //Valorant logo
                      0, 0, 0, 0, 0, 0, 0, 0,
                      1, 0, 0, 0, 0, 0, 0, 1,
                      1, 1, 0, 0, 0, 0, 1, 1,
                      0, 1, 1, 0, 0, 1, 1, 0,
                      0, 0, 1, 1, 0, 0, 0, 0,
                      0, 0, 0, 1, 1, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0);
      break;
    case 5:
      Matrix_Super_Computer();
      break;
    case 6:
      Conways_Game_of_Life();
      break;
    default:
      Mat_Mode = 1;
      break;
  }
}
