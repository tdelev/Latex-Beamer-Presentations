#include <iostream>
#include <cstring>
using namespace std;

class WebPage {
private:
	char url[100];
	char *sodrzina;
public:
	WebPage(char *url = "", char *sodrzina = "") {
		strcpy(this->url, url);
		this->sodrzina = new char[strlen(sodrzina) + 1];
		strcpy(this->sodrzina, sodrzina);
	}
	WebPage(const WebPage& wp) {
		strcpy(this->url, wp.url);
		this->sodrzina = new char[strlen(wp.sodrzina) + 1];
		strcpy(this->sodrzina, wp.sodrzina);
	}
	~WebPage() {
		delete[] sodrzina;
	}
	bool operator==(WebPage& wp) {
		return strcmp(url, wp.url) == 0;
	}
	WebPage operator=(WebPage& wp) {
		if (this != &wp) {
			strcpy(this->url, wp.url);
			delete[] sodrzina;
			this->sodrzina = new char[strlen(wp.sodrzina) + 1];
			strcpy(this->sodrzina, wp.sodrzina);
		}
		return *this;
	}
	char *getUrl() {
		return url;
	}
};

class WebServer {
private:
	char ime[30];
	int count;
	WebPage *wp;
public:
	WebServer(char *ime = "", int count = 0, WebPage *wp = 0) {
		strcpy(this->ime, ime);
		this->count = count;
		this->wp = new WebPage[count];
		for (int i = 0; i < count; i++)
			this->wp[i] = wp[i];
	}
	WebServer(const WebServer &ws) {
		strcpy(this->ime, ws.ime);
		this->count = ws.count;
		this->wp = new WebPage[count];
		for (int i = 0; i < count; i++)
			this->wp[i] = ws.wp[i];
	}
	WebServer& operator=(const WebServer &ws) {
		if (this != &ws) {
			strcpy(this->ime, ws.ime);
			this->count = ws.count;
			delete [] this->wp;
			this->wp = new WebPage[count];
			for (int i = 0; i < count; i++)
				this->wp[i] = ws.wp[i];
		}
		return *this;
	}
	~WebServer() {
		delete[] wp;
	}
	WebServer& operator+=(WebPage webPage) {
		WebPage *tmp = new WebPage[count + 1];
		for (int i = 0; i < count; i++)
			tmp[i] = wp[i];
		tmp[count++] = webPage;
		delete[] wp;
		wp = tmp;
		return *this;
	}
	WebServer& operator-=(WebPage webPage) {
		int newCount = 0;
		WebPage *tmp = new WebPage[count];
		for (int i = 0; i < count; i++) {
			if (!(wp[i] == webPage)) {
				tmp[newCount++] = wp[i];
			}
		}
		delete[] wp;
		wp = tmp;
		count = newCount;
		return *this;
	}
	void listPages() {
		for (int i = 0; i < count; i++)
			cout << wp[i].getUrl() << endl;
	}
};
int main() {
	WebPage wp1("http://www.google.com", "The search engine");
	WebPage wp2("http://www.finki.ukim.mk", "FINKI");
	WebPage wp3("http://www.time.mk", "Site vesti");
	WebServer ws("Server");
	ws += wp1;
	ws += wp2;
	ws += wp3;
	ws.listPages();
	ws -= wp3;
	ws.listPages();
	return 0;
}
