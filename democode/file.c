#include"file.h"

// ����ֵ: �ɹ� 1, ʧ�� 0
// ͨ�� path ���ػ�ȡ��·��
int FileOpenDialog(char* path)
{
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn); // �ṹ��С
	ofn.lpstrFile = (LPWSTR)path; // ·��
	ofn.nMaxFile = MAX_PATH; // ·����С
	ofn.lpstrFilter = (LPWSTR)"All\0*.*\0Text\0*.TXT\0"; // �ļ�����
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	return GetOpenFileName(&ofn);
}
int FileSaveDialog(char* path)
{
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn); // �ṹ��С
	ofn.lpstrFile = (LPWSTR)path; // ·��
	ofn.nMaxFile = MAX_PATH; // ·����С
	ofn.lpstrFilter = (LPWSTR)"All\0*.*\0Text\0*.TXT\0"; // �ļ�����
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	return GetSaveFileName(&ofn);
}
