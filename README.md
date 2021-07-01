# tdd_c_book
Learning Test Driven Development for Embedded C

## prepare (NOT WORKING...why?)
`unity.framework/extras/fixture/build` を作成  
`unity.framework/extras/fixture/build/MakefileWorker.mk` を book の code からコピー  
`unity.framework/extras/fixture/src/unity_fixture_malloc_overrides.h` を book の code からコピー  
`.` に `MakefileUnity.mk` を book の code からコピー  
`MakefileUnity.mk` に 以下を追加  
```
TEST_SRC_DIRS = \
	$(PROJECT_TEST_DIR)\
	$(PROJECT_TEST_DIR)/stdio\
	$(UNITY_HOME)/unity\
	$(UNITY_HOME)/src\
    $(UNITY_HOME)/extras/fixture/src\
    $(UNITY_HOME)/extras/fixture/test\
    $(UNITY_HOME)/extras/memory/src\   # <- add
    $(UNITY_HOME)/extras/memory/test\  # <- add

INCLUDE_DIRS =\
  .\
  $(UNITY_HOME)/src\
  $(UNITY_HOME)/extras/fixture/src\
  $(UNITY_HOME)/extras/fixture/test\
  $(UNITY_HOME)/extras/memory/src\   # <- add
  $(UNITY_HOME)/extras/memory/test\  # <- add
```
