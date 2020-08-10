/**
class singleton {
private:
	singleton() {}
	static singleton *p;
public:
	static singleton *instance();
};

singleton *singleton::p = nullptr;

singleton* singleton::instance() {
	if (p == nullptr)
		p = new singleton();
	return p;
}*/