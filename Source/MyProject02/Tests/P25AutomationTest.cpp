// Source/MyProject02/Tests/P25AutomationTest.cpp
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FP25SmokeTest,
    "MyProject02.P25.SmokeTest",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FP25SmokeTest::RunTest(const FString& Parameters)
{
    TestEqual(TEXT("1+1 should be 2"), 1 + 1, 2);
    return true;
}