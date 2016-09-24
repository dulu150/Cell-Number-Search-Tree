#include <stdio.h>
#include <string.h>
#include <stdlib.h >

//************************************
// Method:    CellNumberStrCompress
// FullName:  CellNumberStrCompress
// Access:    public 
// Returns:   int
// Qualifier: 对源字符串功能进行压缩，降低内存占用
// Parameter: char * pSrcCellNumber
// Parameter: char * pResult
//************************************
int CellNumberStrCompress(char* pSrcCellNumber, char* pResult)
{
	int ulIndex = 0;
	int ulCellNumLen = strlen(pSrcCellNumber);

	/* 入参检查 */
	if((NULL == pSrcCellNumber) || (NULL == pResult))
	{
		printf("Invalid Input:NULL ptr");
		return -1;
	}

	if (0 >= ulCellNumLen)
	{
		printf("Invalid Input:Input str's length is [%d]", ulCellNumLen);
		return -1;
	}

	/* 循环遍历源字符串进行转换，转换过程中检查是否存在非法字符 */
	for (ulIndex = 0; ulIndex < 100; ulIndex++)
	{
		pResult[ulIndex] = pSrcCellNumber[ulIndex*2] + pSrcCellNumber[ulIndex*2 + 1];
	}

	return 0;
}

int main()
{
	/* 单元测试代码 */
	char aStrSrcCellNumber[] = "86138123456";
	char* aCellNumberAfterCompress = NULL;

	/* 为保存结果的缓冲区申请内存 */
	aCellNumberAfterCompress = (char *)malloc(sizeof(char) * strlen(aStrSrcCellNumber));
	if (NULL == aCellNumberAfterCompress)
	{
		printf("malloc failed");
		return -1;
	} 
	else
	{
		CellNumberStrCompress(aStrSrcCellNumber, aCellNumberAfterCompress);
	}
	free(aCellNumberAfterCompress);
	aCellNumberAfterCompress = NULL;
	getchar();
	return 0;
}
