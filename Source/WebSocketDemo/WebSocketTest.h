// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WebSocketsModule.h"
#include "IWebSocket.h"
#include "WebSocketTest.generated.h"

/**
 * 
 */
UCLASS()
class WEBSOCKETDEMO_API UWebSocketTest : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void connectWS();
	UFUNCTION(BlueprintCallable)
		void sendWS();
	UFUNCTION(BlueprintCallable)
		void closeWS();

private:
	TSharedPtr<IWebSocket> socketPtr;
	
};
