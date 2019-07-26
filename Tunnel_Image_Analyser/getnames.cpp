#ifdef OPENCV
#endif OPENCV

#include "darknet.h"
/**
 * @brief getNames  이미지에 표시할 이름목록을 가져오는 함수 qt 환경에서는 list가 모호하기 때문에 따로 빼두었음.
 * @param datacfg
 * @return
 */
char **getNames(char *datacfg)
{
    list *options = read_data_cfg(datacfg);

    char *name_list = option_find_str(options, "names", "data/names.list");
    char **names = get_labels(name_list);

    return names;
}
