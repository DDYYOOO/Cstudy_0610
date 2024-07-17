/*
	拙失切 : 戚疑星
	拙失析 : 2024-07-17
	俳柔 鯉妊 : 五乞軒 因娃拭 企廃 戚背, 疑旋 五乞軒 拝雁, 匂昔斗 紫遂
*/

/*
  坪球 慎蝕     : CPU亜 石嬢 級昔 督析聖 叔楳 獣轍陥. 誤敬嬢稽 叔楳 
  汽戚斗 慎蝕   : 穿蝕 痕呪, static 生稽 識情廃 痕呪亜 煽舌
  琵 慎蝕       : 五乞軒研 呪疑生稽 背薦背醤 馬澗 煽舌 因娃
  什澱 慎蝕     : 五乞軒亜 切疑生稽 背薦鞠澗 煽舌 因娃
*/

// 1. 什澱 慎蝕 : 敗呪 硲窒 call by value 舛左研 妊薄拝 凶, 奄糎 葵精 政走廃辰稽 陥献 衣引研 妊獣馬壱 粛聖 凶 紫遂
// 2. 琵   慎蝕 : 琶推廃 汽戚斗 因娃 幻鏑 旋仙旋社稽 隔生檎 疏製

// 什澱, 琵 慎蝕聖 蟹刊澗 戚政
// 五乞軒 因娃戚 廃舛旋

// 神獄 巴稽酔
// 琵 神獄 巴稽酔 : 琵戚 什澱 因娃聖 徴狛
// 什澱 神獄 巴稽酔 : 什澱戚 琵 因娃聖 徴骨

// 仙瑛 敗呪 : 敗呪亜 切奄切重聖 硲窒馬亀系 廃 板, 巷廃 鋼差
// 琵 神獄 巴稽酔 森獣 : malloc, free敗呪稽 送羨 五乞軒 拝雁 貢 背薦, 

#include"lectures.h"

void AllocateArrary(int count)
{
	int* newPtr = malloc(sizeof(int) * count);

	for (int i = 0; i < count; i++)
	{
		*(newPtr + i) = i + 1;
		printf("%d ", *(newPtr + i));
	}
	free(newPtr);
}


void lectures21()
{
	// 疑旋 五乞軒 拝雁 敗呪 : malloc
	// memory + allocation : 五乞軒 拝雁 敗呪 
	// 匂昔斗 痕呪  = malloc(滴奄);  五乞軒 因娃税 滴奄

	int num1 = 20;
	int* num1Ptr = &num1;
	int* const numPtr2 = malloc(4);
	*numPtr2 = num1;
	
	printf("%d\n", *numPtr2);

	// 疑旋 拝雁廃 五乞軒澗 鋼球獣 背薦背醤 敗
	// free
	free(numPtr2);
	printf("%d\n", numPtr2);

	int Arr[4] = {1, 2, 3, 4};
	int* numPtr3 = malloc(sizeof(int) * 4);  //  4 * 4 = 16
	numPtr3 = Arr;

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", *(numPtr3 + i));
	}
	//free(numPtr3);
	printf("\n");

	// 疑旋生稽 舛呪莫 匂昔斗 滴奄研 持失馬澗 敗呪研 拙失
	printf("森薦 庚薦\n");

	int count;
	scanf_s("%d", &count);
	AllocateArrary(count);
	
	printf("\n");
	// 

	char c = 69;	// 69拭 企誓鞠澗 ASII 庚切 馬蟹亜 窒径
	char c2 = 'a';
	printf("%d\n", c);
	printf("%c\n", c);

	//printf("Hello"); // H, e, l, l, o
	// 庚切伸(string)
	char* s = "Hello";
	printf("%s\n", s);

	// 軒斗群 庚切伸 : "けいしけしい"
	// 陳督析 獣拭 爽社研 鋼発(汽戚斗 慎蝕 煽舌)

	char sArr[5] = { 'H', 'e', 'l', 'l', 'o'};
	
	for (int i = 0; i < 5; i++)
	{
		printf("%c", sArr[i]);
	}
	printf("\n");

	char* s2 = "Hello World";
	printf("%s\n", s2);

	printf("庚切 : %c 焼什徹坪球 : %d\n", *(s2 + 1), *(s2 + 1));	// e
	printf("庚切 : %c 焼什徹坪球 : %d\n", *(s2 + 6), *(s2 + 6));	// W
	printf("庚切 : %c 焼什徹坪球 : %d\n", *(s2 + 10), *(s2 + 10));  // d
	printf("庚切 : %c 焼什徹坪球 : %d\n", *(s2 + 5), *(s2 + 5));    // 句嬢床奄 因拷 庚切
	printf("庚切 : %c 焼什徹坪球 : %d\n", *(s2 + 11), *(s2 + 11));  // 庚切伸税 原走厳拭澗 \'0' = NULL庚切.

	// NULL庚切 : 庚切伸税 原走厳聖 硝形爽奄 是廃 庚切
	
	printf("NULL庚切研 戚遂廃 庚切伸 窒径\n");

	int index = 0;
	
	while (*(s2 + index) != 0)  // 繕闇庚 曽戟
	{
		printf("%c", *(s2 + index));
		index++;
	}


}