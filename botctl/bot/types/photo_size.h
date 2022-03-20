#include "base_file.h"
#include "base_object.h"


namespace bot::types {

class PhotoSize : public BaseFile
{
public:
    inline static const string WIDTH = "width";
    inline static const string HEIGHT = "height";

    int width;
    int height;

    PhotoSize() : BaseFile() {}
    PhotoSize(string&);
    virtual ~PhotoSize() {}

protected:
    virtual void fillDocument(Writer& writer) const;
    virtual void fillObject(Document& document);

private:
    typedef BaseFile Parent;
};

}

