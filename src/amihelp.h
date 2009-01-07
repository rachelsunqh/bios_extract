/**********************************************                                 
**                                                                              
**                                                                              
**      Defines for AmiHelp                                                    
**                                                                              
**                                                                              
***********************************************/                                
                                                                                
#include        <stdio.h>                                                       

byte HelpSystem(byte argc, byte *argv[])
      {
	byte	x;
	byte	ID = 0;

		for( x = 1; x < argc; x++ )
		{
			if(StrCmp(argv[x],"-h") == 0)
			{
				printf("\n"SftName" HelpSystem Starting Now!\n");
				printf("\nThis Program Version Number %s",SftVersion);

#ifndef __LINUX_NOW__			
				printf(
				"\n"SftName" - Decompressor for AmiBIOSes only.\n"
				"\tSupported formats: AMIBIOS'94, AMIBIOS'95 and later\n\n"
				""SftName" performs on 386 or better CPU systems\n"
				"under control of DOS, Win3.xx, Win9x/NT/2K or DosEmu\n\n"
				"Compression schemes include: LZINT\n\n"
				"Modules marked with "IDSign" sign are compressed modules\n\n"
				"\tBug reports mailto: "SftEMail"\n"
				"\t\tCompiled: %s, %s\n",__DATE__,__TIME__);
#else
				printf(
				"\n"SftName" - Decompressor for AmiBIOSes only.\n"
				"\tSupported formats: AMIBIOS'94, AMIBIOS'95 or later\n\n"
				""SftName" performs on 386 or better CPU systems\n"
				"under control of LinuxOS\n\n"
				"Compression schemes include: LZINT\n\n"
				"Modules marked with "IDSign" sign are compressed modules\n\n"
				"\tBug reports mailto: "SftEMail"\n"
				"\t\tCompiled: %s, %s with \n\t\t%s",__DATE__,__TIME__,__VERSION__);
#endif		

				printf("\n");
				return( 0x20 );
			}
			if(StrCmp(argv[x], "-x") == 0) (ID = ID ^ 0x10);
			if(StrCmp(argv[x], "-l") == 0) (ID = ID ^ 0x01);
			if(StrCmp(argv[x], "-d") == 0) (ID = ID ^ 0x80);
		}
		
		    return (ID);
	return(0);

    }

void PrintHeader(byte* EOL)
    {
    printf("\n%c%s%c%s", 0x4, SoftName, 0x4, EOL);
    }

void PrintUsage()
    {
	PrintHeader("");
        printf("%s",CopyRights);
        printf("\n\nUsage: %s <AmiBIOS.BIN> [Options]",SftName);
        printf(
        "\n"
        "\t\tOptions:"
        "\n\t\t\t\"-l\" List Bios Structure"
        "\n\t\t\t\"-x\" eXtract Bios Modules"
        "\n\t\t\t\"-d\" create Directory"
        "\n\t\t\t\"-h\" Help statistics"
        );
        printf("\n\n\t*%s*\n",Url);
    }
