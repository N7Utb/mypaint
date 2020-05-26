#include"file.h"

// 返回值: 成功 1, 失败 0
// 通过 path 返回获取的路径
int FileOpenDialog(char* path)
{
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn); // 结构大小
	ofn.lpstrFile = (LPWSTR)path; // 路径
	ofn.nMaxFile = MAX_PATH; // 路径大小
	ofn.lpstrFilter = (LPWSTR)"All\0*.*\0Text\0*.TXT\0"; // 文件类型
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	return GetOpenFileName(&ofn);
}
int FileSaveDialog(char* path)
{
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn); // 结构大小
	ofn.lpstrFile = (LPWSTR)path; // 路径
	ofn.nMaxFile = MAX_PATH; // 路径大小
	ofn.lpstrFilter = (LPWSTR)"All\0*.*\0Text\0*.TXT\0"; // 文件类型
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	return GetSaveFileName(&ofn);
}
