//
// Created by zhsyourai on 8/4/17.
//

#ifndef XCAPTCHA_CAPTCHA_H
#define XCAPTCHA_CAPTCHA_H

#include <image.h>
#include <answer.h>

class captcha {
 public:
  captcha();

  captcha(const captcha &other);

  captcha(captcha &&other) noexcept;

  template<typename T>
  using uncvref_t = typename std::remove_cv<typename std::remove_reference<T>::type>::type;

  template<typename I, typename std::enable_if<std::is_same<uncvref_t<I>, image>::value, int>::type = 0>
  captcha(I &&i) {
    this->i = new image(std::forward<I>(i));
    this->a = nullptr;
  };

  template<typename I, typename A, typename std::enable_if<
      std::is_same<uncvref_t<I>, image>::value and std::is_same<uncvref_t<A>, answer>::value, int>::type = 0>
  captcha(I &&i, A &&a) {
    this->i = new image(std::forward<I>(i));
    this->a = new answer(std::forward<A>(a));
  };

  captcha &operator=(const captcha &other);

  captcha &operator=(captcha &&other) noexcept;

  image &get_image();

  answer &get_answer();

  const image &get_image() const;

  const answer &get_answer() const;

  virtual ~captcha();

 private:
  image *i;
  answer *a;
};

#endif //XCAPTCHA_CAPTCHA_H
