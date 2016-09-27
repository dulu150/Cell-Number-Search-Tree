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
	for (ulIndex = 0; ulIndex < (ulCellNumLen / 2); ulIndex++)
	{
		pResult[ulIndex] = (pSrcCellNumber[ulIndex*2] - '0') * 10 + (pSrcCellNumber[ulIndex*2 + 1] - '0');
	}

	/* 源字符串可能是包含奇数个字符的号码,最后一个字符需要单独处理 */
	if (0 != (ulCellNumLen % 2))
	{
		pResult[ulIndex] = pSrcCellNumber[ulCellNumLen - 1] - '0';
	}

	return 0;
}

int CellNumberStrDeCompress(char* pSrcCellNumber, char* pResult)
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
	for (ulIndex = 0; ulIndex < ulCellNumLen; ulIndex++)
	{
		pResult[ulIndex*2] = (pSrcCellNumber[ulIndex] / 10) % 10 + '0';
		pResult[ulIndex*2 + 1] = pSrcCellNumber[ulIndex] % 10 + '0';
	}

	return 0;
}

int main()
{
	/* 单元测试代码 */
	char aStrSrcCellNumber[] = "86138123456";
	char* aCellNumberAfterCompress = NULL;
	char* aCellNumberAfterDeCompress = NULL;

	/* 压缩测试：为保存结果的缓冲区申请内存 */
	aCellNumberAfterCompress = (char *)malloc(sizeof(char) * strlen(aStrSrcCellNumber));
	memset(aCellNumberAfterCompress, 0, strlen(aStrSrcCellNumber));
	if (NULL == aCellNumberAfterCompress)
	{
		printf("malloc failed");
		return -1;
	} 
	else
	{
		CellNumberStrCompress(aStrSrcCellNumber, aCellNumberAfterCompress);
		printf("result = [%s]", aCellNumberAfterCompress);
	}

	/* 解压缩测试 */
	aCellNumberAfterDeCompress = (char *)malloc(sizeof(char) * strlen(aStrSrcCellNumber));
	memset(aCellNumberAfterDeCompress, 0, strlen(aStrSrcCellNumber));
	if (NULL == aCellNumberAfterDeCompress)
	{
		printf("malloc failed");
		return -1;
	} 
	else
	{
		CellNumberStrDeCompress(aCellNumberAfterCompress, aCellNumberAfterDeCompress);
		printf("result = [%s]", aCellNumberAfterDeCompress);
	}

	/* 处理完成回退内存申请 */
	free(aCellNumberAfterCompress);
	aCellNumberAfterCompress = NULL;

	free(aCellNumberAfterCompress);
	aCellNumberAfterCompress = NULL;

	getchar();
	return 0;
}
