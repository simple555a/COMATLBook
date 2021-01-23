function GetFileList(dirName)
	Set fso = CreateObject("Scripting.FileSystemObject")
	Set directory = fso.GetFolder(dirName)
	Set GetFileList = directory.files
end function

set fileList = GetFileList("C:\Winnt")
for each file in fileList
  WScript.Echo file.name
next
