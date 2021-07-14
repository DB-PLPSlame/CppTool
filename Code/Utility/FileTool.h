#pragma once
#include <string>
#include <list>
#include <vector>

class FileTool
{
public:
	static std::string GetCurDirectory();	// ��ȡ��ǰģ��ȫ·��
	static std::wstring GetDesktopDirectory();
	static bool ReadFileByLine(const std::string& filePath, std::vector<std::string>& all_line);
	static bool ReadFileByChar(const std::string& filePath, std::vector<char>& all_char, bool filter_space = true);

	static std::wstring GetFileNameNotPath(const std::wstring& filePath);//��ȡ�ļ�����������·��
	static std::wstring GetFileExtension(const std::wstring & strPath);//��ȡ�ļ�����չ��
	static std::wstring RemoveExtension(const std::wstring & strPath);//ȥ���ļ�����չ��
	static std::wstring GetFileNameNotExtension(const std::wstring & strPath);//��ȡ�ļ�������������չ��
	static std::wstring GetFileFolder(const std::wstring & strPath);//��ȡ�ļ����ڵ��ļ���·��
	static void copyFile(const char* src, const char* dst);//�����ļ�
	static int createDirectory(const wchar_t* dir);//����Ŀ¼��������ڣ��򲻻Ḳ��ԭ�����ļ�
	static bool IsFileExist(const wchar_t* strPath);//�ж��ļ���Ŀ¼�Ƿ����
	static bool IsFileExist(const char* strPath);//�ж��ļ���Ŀ¼�Ƿ����
	static void GetFiles(std::string path, std::list<std::string>& files);//��ȡָ��·���µ������ļ�
	static bool DeleteFiles(std::string path);//ɾ��ָ��Ŀ¼�µ������ļ�����ɾ����Ŀ¼
	static bool DeleteFilesEx(std::string path);//ɾ��ָ��Ŀ¼�µ������ļ�������ɾ����Ŀ¼
	static bool moveFile(std::string srcPath, std::string dstPath);//�ƶ�ָ���ļ���ָ��·��

	static bool DeleteOldFiles(std::string path, int seconds);//����path�ļ��У�ɾ��ָ��seconds֮ǰ�޸ĵ���fileExtension��β���ļ�
	static std::wstring ToWindowSeprator(const std::wstring& s);	//ת��Windows·�����
};
