#ifndef LIBCWPP_SIZE_HPP
#define LIBCWPP_SIZE_HPP

namespace libcwpp
{

class Size
{
  public:
    Size(int minWidth, int maxWidth, int minHeight, int maxHeight);

    int minWidth(void);
    int maxWidth(void);

    int minHeight(void);
    int maxHeight(void);

    bool isWidthDynamic(void) const;
    bool isHeightDynamic(void) const;

  private:
    int m_minWidth;
    int m_maxWidth;
    int m_minHeight;
    int m_maxHeight;
}; /* class Size */

} /* namespace libcwpp */

#endif /* LIBCWPP_SIZE_HPP */
