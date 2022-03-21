#pragma once
#include <string>

using namespace std;

class GameObject
{
private:
	//기본속성(인스펙터 - Inspector)//
	string tag;
	string name;
	bool   active;

	//변환속성(트랜스폼 - Transform)//
	float px, py;

public:
	//생성자, 소멸자//
	GameObject(string tag, string name, bool active, float px, float py);
	virtual ~GameObject();

	//게터, 세터//
	string GetTag();
	string GetName();
	bool   GetActive();

	float GetPx();
	float GetPy();

	void SetTag(string tag);
	void SetName(string name);
	void SetActive(bool active);

	void SetPx(float px);
	void SetPy(float py);

	//기본 가상함수//
	virtual void Start()  = 0;
	virtual void Update() = 0;
	virtual void Draw()   = 0;

	//기타 활용 함수//
	void Translate(float x, float y);

	//게임오브젝트 추가/삭제하기//
	void Instantiate(GameObject* obj);
	void Destroy(GameObject* obj);

};

