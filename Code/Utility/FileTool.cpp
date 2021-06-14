#include "FileTool.h"
#ifdef _WIN32
#include <direct.h>
#else
#include <unistd.h>
#endif // WIN32
#include <shlobj.h>
//#pragma comment(lib, "shell32.lib")
#include <codecvt>
#include <windows.h>
#include <fstream>
#include <shlobj.h>
#include <memory>
#include <stdlib.h>
#include <io.h>
#include <algorithm>


std::string FileTool::GetCurDirectory()
{
	char path[128];
	_getcwd(path, sizeof(path));
	return path;
}

std::wstring FileTool::GetDesktopDirectory()
{
	TCHAR path[128];
	//��ȡ��ǰ�û�������·��
	SHGetSpecialFolderPath(0, path, CSIDL_DESKTOPDIRECTORY, 0);
	return path;
}

std::wstring FileTool::GetFileNameNotPath(const std::wstring & filePath)
{
	if (filePath.rfind(L"\\") != filePath.npos)
	{
		return filePath.substr(filePath.rfind(L"\\") + 1).c_str();
	}
	return filePath;
}

std::wstring FileTool::GetFileExtension(const std::wstring & strPath)
{
	std::wstring ret = L"";
	int length = strPath.length();
	int index = strPath.rfind(L'.');
	if (index == -1)
		return L"";
	ret = strPath.substr(index + 1, length - index - 1);
	return ret;
}

//ȥ���ļ�����չ��
std::wstring FileTool::RemoveExtension(const std::wstring & strPath)
{
	std::wstring ret = L"";
	int length = strPath.length();
	int index = strPath.rfind(L'.');
	if (index == -1)
		return L"";
	ret = strPath.substr(0, index);
	return ret;
}

std::wstring FileTool::GetFileNameNotExtension(const std::wstring & strPath)
{
	std::wstring ret = strPath;
	int length = strPath.length();
	int index1 = strPath.rfind(L'\\');
	int index2 = strPath.rfind(L'.');
	if (index1 == -1)
		index1 = 0;
	if (index2 == -1)
		index2 = strPath.length();
	if (index1 > index2)
		return ret;
	if (index1 != 0)
		ret = strPath.substr(index1 + 1, index2 - index1 - 1);
	else
		ret = strPath.substr(index1, index2 - index1);
	return ret;
}

std::wstring FileTool::GetFileFolder(const std::wstring & strPath)
{
	std::wstring ret;
	int length = strPath.length();
	int index = strPath.rfind(L'\\');
	if (index == -1)
		return L"";
	ret = strPath.substr(0, index);
	return ret;
}

void FileTool::copyFile(const char* src, const char* dst)
{
	using namespace std;
	ifstream in(src, ios::binary);
	ofstream out(dst, ios::binary);
	if (!in.is_open())
	{
		exit(EXIT_FAILURE);
	}
	if (!out.is_open())
	{
		exit(EXIT_FAILURE);
	}
	if (src == dst)
	{
		exit(EXIT_FAILURE);
	}
	char buf[2048];
	long long totalBytes = 0;
	while (in)
	{
		in.read(buf, 2048);
		out.write(buf, in.gcount());
		totalBytes += in.gcount();
	}
	in.close();
	out.close();
}

int FileTool::createDirectory(const wchar_t* dir)
{
	return SHCreateDirectoryExW(NULL, dir, NULL);
}

bool FileTool::IsFileExist(const wchar_t* strPath)
{
	if (_waccess(strPath, 0) == -1)
		return false;
	else
		return true;
}

bool FileTool::IsFileExist(const char* strPath)
{
	if (_access(strPath, 0) == -1)
		return false;
	else
		return true;
}

void FileTool::GetFiles(std::string path, std::list<std::string>& files)
{
	//�ļ����  
	long hFile = 0;
	//�ļ���Ϣ  
	struct _finddata_t fileinfo;
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//�����Ŀ¼,����֮  
			//�������,�����б�  
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					GetFiles(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

bool FileTool::DeleteFiles(std::string path)
{
	//�ļ����  
	long   hFile = 0;
	//�ļ���Ϣ  
	struct _finddata_t fileinfo;
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//�����Ŀ¼,����֮  
			//�������,�����б�  
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					DeleteFiles(p.assign(path).append("\\").append(fileinfo.name));
					RemoveDirectoryA(p.assign(path).append("\\").append(fileinfo.name).c_str());
				}
			}
			else
			{
				DeleteFileA(p.assign(path).append("\\").append(fileinfo.name).c_str());
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
	//bool ret = RemoveDirectoryA(path.c_str());//�����Ҫɾ����ǰĿ¼����ȥ������ע��
	return true;
}

//ɾ��ָ��Ŀ¼�µ������ļ�������ɾ����Ŀ¼
bool FileTool::DeleteFilesEx(std::string path)
{
	//�ļ����  
	long   hFile = 0;
	//�ļ���Ϣ  
	struct _finddata_t fileinfo;
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//�����Ŀ¼,����֮  
			//�������,�����б�  
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					DeleteFiles(p.assign(path).append("\\").append(fileinfo.name));
					RemoveDirectoryA(p.assign(path).append("\\").append(fileinfo.name).c_str());
				}
			}
			else
			{
				DeleteFileA(p.assign(path).append("\\").append(fileinfo.name).c_str());
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
	RemoveDirectoryA(path.c_str());//�����Ҫɾ����ǰĿ¼����ȥ������ע��
	return true;
}

bool FileTool::moveFile(std::string srcPath, std::string dstPath)
{
	if (srcPath.empty() || dstPath.empty() || _stricmp(srcPath.c_str(), dstPath.c_str()) == 0)
		return false;
	if (IsFileExist(dstPath.c_str()))
		DeleteFileA(dstPath.c_str());
	return MoveFileA(srcPath.c_str(), dstPath.c_str()) ? true : false;
}

//����path�ļ��У�ɾ��ָ��seconds֮ǰ�޸ĵ���fileExtension��β���ļ�
bool FileTool::DeleteOldFiles(std::string path, int seconds)
{
	FILETIME ftSystemCurrent, ftSystemOld;
	SYSTEMTIME st;
	GetSystemTime(&st);
	SystemTimeToFileTime(&st, &ftSystemCurrent);
	ULARGE_INTEGER u1, offset, u2;
	u1.LowPart = ftSystemCurrent.dwLowDateTime;
	u1.HighPart = ftSystemCurrent.dwHighDateTime;
	offset.QuadPart = UInt32x32To64(seconds, 10000000);
	u2.QuadPart = u1.QuadPart - offset.QuadPart;
	ftSystemOld.dwLowDateTime = u2.LowPart;
	ftSystemOld.dwHighDateTime = u2.HighPart;

	//�ļ����  
	long   hFile = 0;
	//�ļ���Ϣ  
	struct _finddata_t fileinfo;
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*.ini").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//�����Ŀ¼,����֮  
			//�������,�����б�  
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				//if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				//{
				//	deleteOldFiles(p.assign(path).append("\\").append(fileinfo.name),seconds);
				//	RemoveDirectoryA(p.assign(path).append("\\").append(fileinfo.name).c_str());
				//}
			}
			else
			{
				std::string filePath = p.assign(path).append("\\").append(fileinfo.name);
				HANDLE handleFile = CreateFileA(filePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
				if (INVALID_HANDLE_VALUE != handleFile)
				{
					FILETIME ftCreationTime, ftLastAccessTime, ftLastWriteTime;
					GetFileTime(handleFile, &ftCreationTime, &ftLastAccessTime, &ftLastWriteTime);
					int ret = CompareFileTime(&ftSystemOld, &ftLastWriteTime);
					if (ret == 1)//first filetime is later than second file time.
					{
						CloseHandle(handleFile);
						DeleteFileA(filePath.c_str());
					}
					else
						CloseHandle(handleFile);

				}
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
	return true;
}

std::wstring FileTool::ToWindowSeprator(const std::wstring& s)
{
	std::wstring temp = s;
	std::replace(temp.begin(), temp.end(), L'/', L'\\');
	return temp;
}
