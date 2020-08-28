# ComDependency_41309

Reproducer for [Single-File Executable Cannot Use Registration Free COM Interop in .NET 5-Preview 7 #41309](https://github.com/dotnet/runtime/issues/41309)

## Instructions

Use Visual Studio 2019 Preview, start Visual Studio "As Administrator" - you should see [Preview|Admin] in the top right corner of the application

Open solution and build Debug/Release AnyCPU/x64 configuration (Release x64 for disambiguation)

Run App.exe - SUCCEESS

Note that App\bin\Release\net5.0\App.dll.manifest is generated about right, with registration free COM elements

Unregister Lib.dll

Run App.exe - FAILURE

### Using Publish

Use App\Properties\PublishProfiles\FolderProfile.pubxml

App\bin\Release\net5.0\win-x64\App.dll.manifest is generated about right

lib.dll is copied to target folder

Run App.exe - FAILURE

Register Lib.dll

Run App.exe - SUCCESS

## Workaround

Set Isolated = False for the COM dependency

See added app.manifest to the App project; note <file> element added to the default (template) manifest

Build/publish App

Note correct manifest in the produced singlefilehost App.exe

Copy x64\Release\Lib.dll to App\bin\Release\net5.0\win-x64 directory

Unregister Lib.dll

Run App.exe - SUCCESS
