#ifndef FLUX_QT_ACTION_H
#define FLUX_QT_ACTION_H

#include <QVariant>
#include <type_traits>
#include <utility>


namespace flux_qt
{
	template <typename E>
	using is_scoped_enum = std::integral_constant<bool, std::is_enum<E>::value && !std::is_convertible<E, int>::value>;

	class Action final
	{
	public:
		template <class ScopedEnum>
		Action(ScopedEnum type, QVariant& payload, bool error = false, std::enable_if_t<is_scoped_enum<ScopedEnum>::value, ScopedEnum>* = nullptr
			) : type_(static_cast<int>(type)), error_(error), payload_(payload) { }

		template <class ScopedEnum>
		Action(ScopedEnum type, QVariant&& payload = QVariant(), bool error = false, std::enable_if_t<is_scoped_enum<ScopedEnum>::value, ScopedEnum>* = nullptr
			) : type_(static_cast<int>(type)), error_(error), payload_(std::move(payload)) { }

		Action(const Action&) = default;
		Action(Action&&) = default;
		Action& operator=(const Action&) = default;
		Action& operator=(Action&&) = default;
		~Action() = default;

		template <class ScopedEnum>
		std::enable_if_t<is_scoped_enum<ScopedEnum>::value, ScopedEnum> getType() const {
			return static_cast<ScopedEnum>(type_);
		}

		template <class T>
		T getPayload() const {
			return qvariant_cast<T>(payload_);
		}

		bool getError() const {
			return error_;
		}

	private:
		int type_;
		bool error_;
		QVariant payload_;
	};
}

#endif
