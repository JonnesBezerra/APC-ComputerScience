#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Funcao que transforma os infectados em doentes
void ficar_doente(int matriz[][100], int x){
	int pL, pC, i;

	srand(time(NULL));

	for (i = 0; i < x; i++){
		do{
			pL = rand() % 100;
			pC = rand() % 100;
		} while (matriz[pL][pC] != 2);
		matriz[pL][pC] = 3;
	}
}

//Funcao que cura doente ou mata
int curar_doente(int matriz[][100], int x){
	int pL, pC, i, j, vida, vivos = x*0.9, mortos=0;

	srand(time(NULL));

	for (i = 0; i < vivos; i++){
		do{
			pL = rand() % 100;
			pC = rand() % 100;
		} while (matriz[pL][pC] != 3);
		matriz[pL][pC] = 1;
		x--;
	}

	for (i = 0; i < x; i++){
		do{
			pL = rand() % 100;
			pC = rand() % 100;
		} while (matriz[pL][pC] != 3);
		matriz[pL][pC] = 0;
		mortos++;
	}

	return mortos;
}

//Funcao que infecta no raio de 3
int infectar_raio3 (int matriz[][100]){
	int i, j, a, b, c, d, e, f, infec=0, infec_Dia=0, infe;
	int pos_LinhaInfec[5001], pos_ColunaInfec[5001];

	srand(time(NULL));
	for (i = 0; i < 100; i++){
		for (j = 0; j < 100; j++){
			if (matriz[i][j] == 2){
				pos_LinhaInfec[infec] = i;
				pos_ColunaInfec[infec] = j;
				infec++;
			}
		}
	}

	for (i = 0; i < infec; i++){
		c = 3;
		d = 3;
		e = 3;
		f = 3;
		while ((pos_LinhaInfec[i] - c) < 0){
			c--;
		}
		while ((pos_ColunaInfec[i] - d) < 0){
			d--;
		}
		while ((pos_LinhaInfec[i] + e) > 99){
			e--;
		}
		while ((pos_ColunaInfec[i] + f) > 99){
			f--;
		}
		for (a = (pos_LinhaInfec[i] - c); a < (pos_LinhaInfec[i] + e + 1); a++){
			for (b = (pos_ColunaInfec[i] - d); b < (pos_ColunaInfec[i] + f + 1); b++){
				if (matriz[a][b] == 1){
					infe = 1 + rand() % 100;
					if (infe < 75){
						matriz[a][b] = 2;
						infec_Dia++;
					}
				}
			}
		}
	}

	infec = 0;
	for (i = 0; i < 100; i++){
		for (j = 0; j < 100; j++){
			if (matriz[i][j] == 3){
				pos_LinhaInfec[infec] = i;
				pos_ColunaInfec[infec] = j;
				infec++;
			}
		}
	}

	for (i = 0; i < infec; i++){
		c = 3;
		d = 3;
		e = 3;
		f = 3;
		while (pos_LinhaInfec[i] - c < 0){
			c--;
		}
		while (pos_ColunaInfec[i] - d < 0){
			d--;
		}
		while (pos_LinhaInfec[i] + e > 99){
			e--;
		}
		while (pos_ColunaInfec[i] + f > 99){
			f--;
		}
		for (a = pos_LinhaInfec[i] - c; a < pos_LinhaInfec[i] + e + 1; a++){
			for (b = pos_ColunaInfec[i] - d; b < pos_ColunaInfec[i] + f + 1; b++){
				if (matriz[a][b] == 1){
					infe = 1 + rand() % 100;
					if (infe < 75){
						matriz[a][b] = 2;
						infec_Dia++;
					}
				}
			}
		}
	}
	return infec_Dia;
}

int main(int *argc , char const *agrv[]) {

	int cidade[100][100];
	int pos_Linha, pos_Coluna, i, j, cont_saud=0, cont_infec=0, seg, a, c, movimento, mov_valido, infec, cont_doentes, morto=0, infecTotal=5;
	int pos_LinhaSaud[5001], pos_ColunaSaud[5001], pos_LinhaInfec[5001], pos_ColunaInfec[5001],infec_Dia[1800];

	//Gerando uma semente aleatoria
	srand(time(NULL));

	//Zerando a matriz da cidade
	for(i = 0; i < 100; i++){
		for(j = 0; j < 100; j++){
			cidade[i][j] = 0;
		}
	}

	//Definindo os habitantes
	for(i = 0; i < 5000; i++){
		do{
			pos_Linha = rand() % 100;
			pos_Coluna = rand() % 100;
		} while (cidade[pos_Linha][pos_Coluna] != 0);
		cidade[pos_Linha][pos_Coluna] = 1;
	}

	//Definindo os primeiros infectados
	for(i = 0; i < 5; i++){
		do{
			pos_Linha = rand() % 100;
			pos_Coluna = rand() % 100;
		} while (cidade[pos_Linha][pos_Coluna] != 1);
		cidade[pos_Linha][pos_Coluna] = 2;
	}

	infec_Dia[0] = 5;
	//Atualizando a matriz a cada 2 segundos
	for (seg = 0; seg < 1801; seg++){
		a = 0;
		infec = 0;
		cont_doentes = 0;
		//Verificando a posicao dos saudaveis
		for (i = 0; i < 100; i++){
			for (j = 0; j < 100; j++){
				if (cidade[i][j] == 1){
					pos_LinhaSaud[a] = i;
					pos_ColunaSaud[a] = j;
					a++;
				} else if (cidade[i][j] == 2){
					pos_LinhaInfec[infec] = i;
					pos_ColunaInfec[infec] = j;
					infec++;
				}
			}
		}
		//Movimentacao dos saudaveis
		for (int x = 0; x < (a/2); x++){
			//Garantindo que o saudavel nao esteja cercado por outras pessoas
			//Primeiro caso: 1 Nao estando nas bordas
			c = rand() % a;
			if ((pos_LinhaSaud[c] > 0) && (pos_LinhaSaud[c] < 99) && (pos_ColunaSaud[c] > 0) && (pos_ColunaSaud[c] < 99)){
				if ((cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] == 0) || (cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] == 0) || (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] == 0) || (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] == 0)){
					cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]] = 0;
					mov_valido = 0;
					do{
						movimento = 1  + rand() % 4;
						switch (movimento){
							case 1: //Mover para baixo
								if (cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] == 0){
									cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] = 1;
									mov_valido++;
								}
								break;
							case 2: //Mover para cima
								if (cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] == 0){
									cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] = 1;
									mov_valido++;
								}
								break;
							case 3: //Mover para a direita
								if (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] == 0){
									cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] = 1;
									mov_valido++;
								}
								break;
							case 4: //Mover para a esquerda
								if (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] == 0){
									cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] = 1;
									mov_valido++;
								}
						}
					} while (mov_valido == 0);
				}
			} else if (pos_LinhaSaud[c] == 0){ //Segundo caso: Primeira Linha
				// Caso 2.1: Linha 0, Coluna 0
				if (pos_ColunaSaud[c] == 0){
					if((cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] == 0) || (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] == 0)){
						cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]] = 0;
						mov_valido = 0;
						do{
							movimento = 1 + rand() % 2;
							switch (movimento){
								case 1: //Andar para baixo
									if (cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] == 0){
										cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] = 1;
										mov_valido++;
									}
									break;
								case 2: //Andar para a direita
									if (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] == 0){
										cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1]=1;
										mov_valido++;
									}
							}
						} while (mov_valido == 0);
					}
				} else if (pos_ColunaSaud[c] == 99){ //Caso 2.2: Linha 0, coluna 9
					if ((cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] == 0) || (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] == 0)){
						cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]] = 0;
						mov_valido = 0;
						do{
							movimento = 1 + rand() % 2;
							switch (movimento){
								case 1: //Andar para baixo
									if (cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] == 0){
										cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] = 1;
										mov_valido++;
									}
									break;
								case 2: //Andar para a esquerda
									if (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] == 0){
										cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] = 1;
										mov_valido++;
									}
							}
						} while (mov_valido == 0);
					}
				} else {
					//Linha 0, coluna entre 0 e 9
					if(cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]]==0 || cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1]==0 || cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1]==0){
						cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]]=0;
						mov_valido=0;
						do{
							movimento = 1 + rand() % 3;
							switch (movimento){
								case 1: //Andar para baixo
									if (cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] == 0){
										cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] = 1;
										mov_valido++;
									}
									break;
								case 2: //Andar para a esquerda
									if (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] == 0){
										cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] = 1;
										mov_valido ++;
									}
									break;
								case 3: //Mover para a direita
									if (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] == 0){
										cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] = 1;
										mov_valido++;
									}
							}
						} while (mov_valido == 0);
					}
				}
			} else if (pos_LinhaSaud[c] == 99){ //Ultima linha
				//Primeira coluna
				if (pos_ColunaSaud[c] == 0){
					if ((cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] == 0) || (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] == 0)){
						cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]] = 0;
						mov_valido = 0;
						do{
							movimento = 1 + rand() % 2;
							switch (movimento){
								case 1: //Andar para cima
									if (cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] == 0){
										cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] = 1;
										mov_valido++;
									}
									break;
								case 2: //Andar para a direita
									if (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] == 0){
										cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] = 1;
										mov_valido++;
									}
							}
						} while (mov_valido == 0);
					}
				} else if (pos_ColunaSaud[c] == 99){ //Ultima Linha, Ultima coluna
					if ((cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] == 0) || (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] == 0)){
						cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]] = 0;
						mov_valido = 0;
						do{
							movimento = 1 + rand() % 2;
							switch (movimento){
								case 1: //Andar para cima
									if (cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] == 0){
										cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] = 1;
										mov_valido++;
									}
									break;
								case 2: //Andar para a esquerda
									if (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] == 0){
										cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] = 1;
										mov_valido++;
									}
									break;
							}
						} while (mov_valido == 0);
					}
				} else { //Ultima Linha, Coluna dos meios
					if ((cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] == 0) || (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] == 0) || (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] == 0)){
						cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]] = 0;
						mov_valido = 0;
						do{
							movimento = 1 + rand() % 3;
							switch (movimento){
								case 1: //Andar para cima
									if (cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] == 0){
										cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] = 1;
										mov_valido++;
									}
									break;
								case 2: //Andar para a esquerda
									if (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] == 0){
										cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] = 1;
										mov_valido++;
									}
									break;
								case 3: //Mover para a direita
									if (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] == 0){
										cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] = 1;
										mov_valido++;
									}
							}
						} while (mov_valido == 0);
					}
				}
			} else if (pos_ColunaSaud[c] == 0){ //Primeira coluna entre as linhas 0 e 9
				if ((cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] == 0) || (cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] == 0) || (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] == 0)){
					cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]] = 0;
					mov_valido = 0;
					do{
						movimento = 1 + rand() %  3;
						switch (movimento){
							case 1: //Andar para baixo
								if (cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] == 0){
									cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] = 1;
									mov_valido++;
								}
								break;
							case 2: //Andar para cima
								if (cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] == 0){
									cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] = 1;
									mov_valido++;
								}
								break;
							case 3: //Andar para a direita
								if (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] == 0){
									cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]+1] = 1;
									mov_valido++;
								}
						}
					} while (mov_valido == 0);
				}
			} else if (pos_ColunaSaud[c] == 99){
				if ((cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] == 0) || (cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] == 0) || (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] == 0)){
					cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]] = 0;
					mov_valido = 0;
					do{
						movimento = 1 + rand() %  3;
						switch (movimento){
							case 1: //Andar para baixo
								if (cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] == 0){
									cidade[pos_LinhaSaud[c]+1][pos_ColunaSaud[c]] = 1;
									mov_valido++;
								}
								break;
							case 2: //Andar para cima
								if (cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] == 0){
									cidade[pos_LinhaSaud[c]-1][pos_ColunaSaud[c]] = 1;
									mov_valido++;
								}
								break;
							case 3: //Andar para a esquerda
								if (cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] == 0){
									cidade[pos_LinhaSaud[c]][pos_ColunaSaud[c]-1] = 1;
									mov_valido++;
								}
						}
					} while (mov_valido == 0);
				}
			}
		}
		//Movimentação dos infectados
		for (int x = 0; x < (infec/2); x++){
			//Garantindo que o infectado não esteja cercado por outras pessoas
			//Primeiro caso: 2 Nao estando nas bordas
			c = rand() % infec;
			if ((pos_LinhaInfec[c] > 0) && (pos_LinhaInfec[c] < 99) && (pos_ColunaInfec[c] > 0) && (pos_ColunaInfec[c] < 99)){
				if ((cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] == 0) || (cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] == 0) || (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] == 0) || (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] == 0)){
					cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]] = 0;
					mov_valido = 0;
					do{
						movimento = 1  + rand() % 4;
						switch (movimento){
							case 1: //Mover para baixo
								if (cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] == 0){
									cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] = 2;
									mov_valido++;
								}
								break;
							case 2: //Mover para cima
								if (cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] == 0){
									cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] = 2;
									mov_valido++;
								}
								break;
							case 3: //Mover para a direita
								if (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] == 0){
									cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] = 2;
									mov_valido++;
								}
								break;
							case 4: //Mover para a esquerda
								if (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] == 0){
									cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] = 2;
									mov_valido++;
								}
						}
					} while (mov_valido == 0);
				}
			} else if (pos_LinhaInfec[c] == 0){ //Segundo caso: Primeira Linha
				// Caso 2.1: Linha 0, Coluna 0
				if (pos_ColunaInfec[c] == 0){
					if ((cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] == 0) || (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] == 0)){
						cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]] = 0;
						mov_valido = 0;
						do{
							movimento = 1 + rand() % 2;
							switch (movimento){
								case 1: //Andar para baixo
									if (cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] == 0){
										cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] = 2;
										mov_valido++;
									}
									break;
								case 2: //Andar para a direita
									if (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] == 0){
										cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] = 2;
										mov_valido++;
									}
							}
						} while (mov_valido == 0);
					}
				} else if (pos_ColunaInfec[c] == 99){ //Caso 2.2: Linha 0, coluna 9
					if ((cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] == 0) || (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] == 0)){
						cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]] = 0;
						mov_valido = 0;
						do{
							movimento = 1 + rand() % 2;
							switch (movimento){
								case 1: //Andar para baixo
									if (cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] == 0){
										cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] = 2;
										mov_valido++;
									}
									break;
								case 2: //Andar para a esquerda
									if (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] == 0){
										cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] = 2;
										mov_valido++;
									}
							}
						} while (mov_valido == 0);
					}
				} else {
					//Linha 0, coluna entre 0 e 9
					if ((cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] == 0) || (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] == 0) || (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] == 0)){
						cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]] = 0;
						mov_valido = 0;
						do{
							movimento = 1 + rand() % 3;
							switch (movimento){
								case 1: //Andar para baixo
									if (cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] == 0){
										cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] = 2;
										mov_valido++;
									}
									break;
								case 2: //Andar para a esquerda
									if (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] == 0){
										cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] = 2;
										mov_valido++;
									}
									break;
								case 3: //Mover para a direita
									if (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] == 0){
										cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] = 2;
										mov_valido++;
									}
							}
						} while (mov_valido == 0);
					}
				}
			} else if (pos_LinhaInfec[c] == 99){ //Ultima linha
				//Primeira coluna
				if (pos_ColunaInfec[c] == 0){
					if ((cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] == 0) || (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] == 0)){
						cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]] = 0;
						mov_valido = 0;
						do{
							movimento = 1 + rand() % 2;
							switch (movimento){
								case 1: //Andar para cima
									if (cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] == 0){
										cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] = 2;
										mov_valido++;
									}
									break;
								case 2: //Andar para a direita
									if (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] == 0){
										cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] = 2;
										mov_valido++;
									}
							}
						} while (mov_valido == 0);
					}
				} else if (pos_ColunaInfec[c] == 99){ //Ultima Linha, Ultima coluna
					if ((cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] == 0) || (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] == 0)){
						cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]] = 0;
						mov_valido = 0;
						do{
							movimento = 1 + rand() % 2;
							switch (movimento){
								case 1: //Andar para cima
									if (cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] == 0){
										cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] = 2;
										mov_valido++;
									}
									break;
								case 2: //Andar para a esquerda
									if (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] == 0){
										cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] = 2;
										mov_valido++;
									}
									break;
							}
						} while (mov_valido == 0);
					}
				} else {  //Ultima Linha, Coluna dos meios
					if ((cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] == 0) || (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] == 0) || (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] == 0)){
						cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]] = 0;
						mov_valido = 0;
						do{
							movimento = 1 + rand() % 3;
							switch (movimento){
								case 1: //Andar para cima
									if (cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] == 0){
										cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] = 2;
										mov_valido++;
									}
									break;
								case 2: //Andar para a esquerda
									if (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] == 0){
										cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] = 2;
										mov_valido++;
									}
									break;
								case 3: //Mover para a direita
									if (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] == 0){
										cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] = 2;
										mov_valido++;
									}
							}
						} while (mov_valido == 0);
					}
				}
			} else if (pos_ColunaInfec[c]==0){ //Primeira coluna entre as linhas 0 e 9
				if ((cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] == 0) || (cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] == 0) || (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] == 0)){
					cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]] = 0;
					mov_valido = 0;
					do{
						movimento = 1 + rand() %  3;
						switch (movimento){
							case 1: //Andar para baixo
								if (cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] == 0){
									cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] = 2;
									mov_valido++;
								}
								break;
							case 2: //Andar para cima
								if (cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] == 0){
									cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] = 2;
									mov_valido++;
								}
								break;
							case 3: //Andar para a direita
								if (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] == 0){
									cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]+1] = 2;
									mov_valido++;
								}
						}
					} while (mov_valido == 0);
				}
			} else if (pos_ColunaInfec[c] == 99){
				if ((cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] == 0) || (cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] == 0) || (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] == 0)){
					cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]] = 0;
					mov_valido = 0;
					do{
						movimento = 1 + rand() %  3;
						switch (movimento){
							case 1: //Andar para baixo
								if (cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] == 0){
									cidade[pos_LinhaInfec[c]+1][pos_ColunaInfec[c]] = 2;
									mov_valido++;
								}
								break;
							case 2: //Andar para cima
								if (cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] == 0){
									cidade[pos_LinhaInfec[c]-1][pos_ColunaInfec[c]] = 2;
									mov_valido++;
								}
								break;
							case 3: //Andar para a esquerda
								if (cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] == 0){
									cidade[pos_LinhaInfec[c]][pos_ColunaInfec[c]-1] = 2;
									mov_valido++;
								}
						}
					} while (mov_valido == 0);
				}
			}
		}	
		if (seg > 0) {
			infec_Dia[seg] = infectar_raio3(cidade);
			infecTotal += infec_Dia[seg];
		}

		if (seg >= 30){
			ficar_doente(cidade, infec_Dia[seg-30]);
		}
		
		if (seg >= 48){
			morto += curar_doente(cidade, infec_Dia[seg-48]);
		}
		infec = 0;
		a = 0;
		cont_doentes = 0;
		for (i = 0; i < 100; i++){
			for (j = 0; j < 100; j++){
				if (cidade[i][j] == 1){
					a++;
				} else if (cidade[i][j] == 2){
					infec++;
				} else if (cidade[i][j] == 3){
					cont_doentes++;
				}
			}
		}
		
		if (infecTotal < 5000){
			printf("\nDia [%d]\n[%d] infectados totais\n[%d] infectados no dia\n[%d] mortos.\n", seg, infecTotal, infec_Dia[seg], morto);
		} else {
			printf("\nDia [%d]\n[5000] infectados totais\n[%d] infectados no dia\n[%d] mortos.\n", seg, infec_Dia[seg], morto);
		}
	
		sleep(2);
	}
	
	return 0;
}