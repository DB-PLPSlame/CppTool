//++Base64.h
#pragma once
#include <string>

class Base64
{
public:
	Base64() = default;
	~Base64() = default;

	/*����
	DataByte
	[in]��������ݳ���,���ֽ�Ϊ��λ
	*/
	static std::string Encode(const char* Data, int DataByte);

	/*����
	DataByte
	[in]��������ݳ���,���ֽ�Ϊ��λ
	OutByte
	[out]��������ݳ���,���ֽ�Ϊ��λ,�벻Ҫͨ������ֵ����
	������ݵĳ���
	*/
	static std::string Decode(const char* Data, int DataByte, int& OutByte);
	static bool FileToBase64(const std::string& file_path, std::string& base64);
	static bool Base64ToFile(const std::string& file_path, const std::string& base64);
};

