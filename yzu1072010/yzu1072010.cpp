// yzu1072010.cpp : 定義 DLL 應用程式的匯出函式。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

extern "C" __declspec(dllexport) bool __cdecl PokerGame(int *card, int *yourcardstyle, LPCWSTR enemy)
{
	int three[3] = { 0,0,0 };                     //用來儲存三種牌型 
	int five1[5] = { 0,0,0,0,0 };
	int five2[5] = { 0,0,0,0,0 };
	int bf[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };   //用陣列存取個數字的排有幾張 
	int mycard[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int cardstyle[13];
	int a[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < 13; i++)
	{
		a[i] = card[i];
	}

	for (int i = 0; i < 13; i++) {        //將牌傳入自己的陣列 
		cardstyle[i] = card[i];
	}
	for (int j = 0; j < 13; j++) {       //將所有數字都換成1~13 
		if (cardstyle[j] <= 13) {
			//cout << cardstyle[j] << " ";
		}
		else if (cardstyle[j] > 13) {
			if (cardstyle[j] % 13 == 0) {
				cardstyle[j] = 13;
			}
			else {
				cardstyle[j] = cardstyle[j] % 13;
			}
		}
	}
	for (int i = 0; i < 13; i++) {               //將換算好的牌按照順序排好 
		for (int j = i + 1; j < 13; j++) {
			if (cardstyle[j] < cardstyle[i]) {
				int q;
				q = cardstyle[j];
				cardstyle[j] = cardstyle[i];
				cardstyle[i] = q;
			}
		}
	}

	for (int i = 0; i < 13; i++) {
		int w = 0;
		w = cardstyle[i] - 1;
		bf[w]++;
	}
	for (int i = 12; i >= 0; i--) { 
		if (bf[i] == 4) {                           //鐵支                          
			for (int j = 0; j < 4; j++) {
				five2[j] = i + 1;
			}
			for (int p = 1; p < 13; p++) {
				if (bf[p] == 1) {
					five2[4] = p + 1;
					bf[p] -= 1;                  //找到之後要扣掉不然後面會重複找 以下都同理 
					break;
				}
			}
			bf[i] -= 4;
			for (int x = 12; x >= 0; x--) {
				if (bf[x] == 4) {                           //鐵支
					bf[x] -= 4;
					for (int j = 0; j < 4; j++) {
						five1[j] = x + 1;
					}
					for (int p = 1; p < 13; p++) {
						if (bf[p] == 1) {
							five1[4] = p + 1;
							bf[p] -= 1;                  //找到之後要扣掉不然後面會重複找 以下都同理 
							break;
						}
					}
				}
			}
			for (int y = 12; y >= 0; y--) {
				if (bf[y] == 3) {                     //葫蘆 
					bf[y] -= 3;
					for (int j = 0; j < 3; j++) {
						five1[j] = y + 1;
					}
					for (int p = 0; p < 13; p++) {               //找的到pair湊葫蘆  
						if (bf[p] == 2) {
							five1[3] = p + 1;
							five1[4] = p + 1;
							bf[p] -= 2;
							break;
						}
					}
					//break;
				}
			}

			for (int z = 12; z >= 0; z--) {
				if (bf[z] == 2) {                     //2pairs 
					bf[z] -= 2;
					for (int j = 0; j < 2; j++) {
						five1[j] = z + 1;

					}
					for (int p = 0; p < 13; p++) {
						if (bf[p] == 2) {
							five1[2] = p + 1;
							five1[3] = p + 1;
							bf[p] -= 2;
							break;
						}
					}
					for (int k = 0; k < 13; k++) {
						if (bf[k] == 1) {
							five1[4] = k + 1;
							bf[k] -= 1;
							break;
						}
					}
					break;
				}
			}
		}

	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 12; i >= 0; i--) {
		if (bf[i] == 3) {                     //葫蘆 
			bf[i] -= 3;
			for (int j = 0; j < 3; j++) {
				five2[j] = i + 1;

			}
			for (int p = 0; p < 13; p++) {             //找的到pair湊葫蘆  
				if (bf[p] == 2) {
					five2[3] = p + 1;
					five2[4] = p + 1;
					bf[p] -= 2;
					break;
				}
			}
			for (int y = 12; y >= 0; y--) {
				if (bf[y] == 3) {                     //葫蘆 
					bf[y] -= 3;
					for (int j = 0; j < 3; j++) {
						five1[j] = y + 1;

					}
					for (int p = 0; p < 13; p++) {               //找的到pair湊葫蘆  
						if (bf[p] == 2) {
							five1[3] = p + 1;
							five1[4] = p + 1;
							bf[p] -= 2;
							break;
						}
					}
					//break;
				}
			}
			for (int z = 12; z >= 0; z--) {
				if (bf[z] == 2) {                     //2pairs 
					bf[z] -= 2;
					for (int j = 0; j < 2; j++) {
						five1[j] = z + 1;

					}
					for (int p = 0; p < 13; p++) {
						if (bf[p] == 2) {
							five1[2] = p + 1;
							five1[3] = p + 1;
							bf[p] -= 2;
							break;
						}
					}
					for (int k = 0; k < 13; k++) {
						if (bf[k] == 1) {
							five1[4] = k + 1;
							bf[k] -= 1;
							break;
						}
					}
					break;
				}
			}
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 12; i >= 0; i--) {
		if (bf[i] == 2) {                     //2pairs 
			for (int j = 0; j < 2; j++) {
				five2[j] = i + 1;
			}
			bf[i] -= 2;
			for (int p = 0; p < 13; p++) {
				if (bf[p] == 2) {
					five2[2] = p + 1;
					five2[3] = p + 1;
					bf[p] -= 2;
					break;
				}
			}
			for (int k = 0; k < 13; k++) {
				if (bf[k] == 1) {
					five2[4] = k + 1;
					bf[k] -= 1;
					break;
				}
			}
			for (int z = 12; z >= 0; z--) {
				if (bf[z] == 2) {                     //2pairs 
					for (int j = 0; j < 2; j++) {
						five1[j] = z + 1;
					}
					bf[z] -= 2;
					for (int p = 0; p < 13; p++) {
						if (bf[p] == 2) {
							five1[2] = p + 1;
							five1[3] = p + 1;
							bf[p] -= 2;
							break;
						}
					}
					for (int k = 0; k < 13; k++) {
						if (bf[k] == 1) {
							five1[4] = k + 1;
							bf[k] -= 1;
							break;
						}
					}
				}
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 5; i++) {              //放數字進空的(=0)陣列裡面
		if (five2[i] == 0) {
			for (int j = 12; j >= 0; j--) {
				if (bf[j] != 0) {
					five2[i] = j + 1;
					bf[j] -= 1;
					break;
				}
			}
		}
	}
	for (int i = 0; i < 5; i++) {             //同上
		if (five1[i] == 0) {
			for (int j = 12; j >= 0; j--) {
				if (bf[j] != 0) {
					five1[i] = j + 1;
					bf[j] -= 1;
					break;
				}
			}
		}
	}
	///////////////////////////////////////////////////////////////////////////////
	int count1 = 0;             //記迴圈跑的次數 
	int q = 0;                  //記three陣列內的三個數 
	while (count1 < 3) {        //把剩餘的牌都放進three陣列裡
		for (int i = 0; i < 13; i++) {
			if (bf[i] != 0) {
				bf[i] -= 1;
				three[q] = i + 1;
				q++;
			}
		}
		count1++;
	}

	for (int i = 0; i < 3; i++) {
		mycard[i] = three[i];
	}

	mycard[3] = five1[0];            //將five1和five2陣列內的牌丟進mycard
	mycard[4] = five1[1];
	mycard[5] = five1[2];
	mycard[6] = five1[3];
	mycard[7] = five1[4];
	mycard[8] = five2[0];
	mycard[9] = five2[1];
	mycard[10] = five2[2];
	mycard[11] = five2[3];
	mycard[12] = five2[4];
	for (int i = 0; i < 13; i++) {                //把牌轉換回原本的數字(利用餘數相同)
		for (int j = 0; j < 13; j++) {
			if (mycard[i] == (a[j] % 13) && a[j] != 0 && a[j] % 13 != 0) {
				mycard[i] = a[j];
				a[j] = 0;
				break;
			}
			else if (mycard[i] == 13 && (a[j] % 13 == 0) && a[j] != 0) {
				mycard[i] = a[j];
				a[j] = 0;
				break;
			}
		}
	}
	for (int i = 0; i < 13; i++)                   //將值回傳
	{
		yourcardstyle[i] = mycard[i];
	}
	std::wcout << enemy << std::endl;
	return true;
}