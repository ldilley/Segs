#ifndef SCRIPTINGENGINE_H
#define SCRIPTINGENGINE_H
#include <memory>

class QString;
class MapClient;

class ScriptingEngine
{
public:
    ScriptingEngine();
    ~ScriptingEngine();
    void registerTypes();
    int runScript(const QString &script_contents,const char *script_name="unnamed script");
    int runScript(MapClient *client,const QString &script_contents,const char *script_name="unnamed script");
private:
#ifdef SCRIPTING_ENABLED
    struct ScriptingEnginePrivate;
    std::unique_ptr<ScriptingEnginePrivate> m_private;
#endif
};

#endif // SCRIPTINGENGINE_H