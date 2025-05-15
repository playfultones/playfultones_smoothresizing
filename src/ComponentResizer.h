#pragma once

namespace PlayfulTones
{
    class ComponentResizer
    {
    public:
        ComponentResizer (juce::Component& componentToResize);

        void setTransformedBounds (const juce::Rectangle<float>& bounds);

        static juce::AffineTransform getRectTransform (const juce::Rectangle<float>& source,
            const juce::Rectangle<float>& target);

        static void drawFittedTextFloat (juce::Graphics& g,
            const juce::String& text,
            juce::Rectangle<float> area,
            juce::Justification justification,
            const int maximumNumberOfLines,
            const float minimumHorizontalScale = 0.0f);

    private:
        juce::Component& component;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComponentResizer)
    };
} // namespace PlayfulTones
