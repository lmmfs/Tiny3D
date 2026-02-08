#pragma once

#include <stdint.h>

#include "Tiny.h"

class MainLayer : public Tiny3d::Layer {
public:
	MainLayer();
	virtual ~MainLayer();

    virtual void OnUpdate(float ts) override;
	virtual void OnRender() override;
private:
	
};